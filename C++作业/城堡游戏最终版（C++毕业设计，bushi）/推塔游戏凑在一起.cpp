#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
enum color{red,blue};
int now_time=0;
class warrior;
class city
{
	private:
		warrior* redw_Buff;
		warrior* bluew_Buff;
		//-1代表红方基地，0代表正常城市,1代表蓝方基地 
		int HQ_flag;
	public:
		warrior* redw;
		warrior* bluew;
		int city_serial;
		city(int city_serial,int HQ_flag);
		//武士到达 
		void warrior_arrived(warrior* x);
		//武士离开 
		void warrior_left(warrior* x);
		//检查是否发生wolf抢夺武器
		void check_rob(); 
		//检查是否能发生战斗 
		void check_battle();
		friend class Procedure;
		virtual ~city();
};
class HQ;
class warrior;
class weapon;
warrior* choose_worrior_by_name(std::string s,int serial,int health,int force,HQ* HQ_belonged,color camp);
weapon* choose_weapon_by_serial(int serial,warrior* owner);
bool weapons_resort(weapon* a,weapon* b);
bool weapons_resort_for_rob(weapon* a,weapon* b);
void print_now_time();
class Red_HQ;
class Blue_HQ;
class city;
class Procedure
{
	private:
		int total_time;
		std::map<int,city*> cities;
		int citys_num;
		Red_HQ* Red;
		Blue_HQ* Blue;
		void init_warrior_round_unfinished();
	public:
		Procedure(int Health,int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h,int dragon_f,int ninja_f,\
		int iceman_f,int lion_f,int wolf_f,int citys_num,int loyalty_rate,int total_time);
		void begin();
		void events();
};
class warrior; 
class HQ:public city
{
	protected:
		//阵营（红蓝）
		color camp; 
		//基地当前将要制造的兵种
		std::string now_troop; 
		//下一个要生产的兵种的编号
		int serial=1; 
		//基地当前是否还在产兵
		bool is_producting=true; 
//		//各类兵种的数量 
//		std::map<std::string,int> troop_num;
		//各类兵种的生命值
		std::map<std::string,int> troop_health;
		//各类兵种的攻击力
		std::map<std::string,int> troop_force;
		//要打印的信息:
		//报告武士出生 
		virtual void print1()=0;
		//宣布停止造兵 
		virtual void print2()=0; 
		//造兵的方法 
		void build_troop(); 
	public:
		//lion忠诚度的下降速度
		int loyalty_rate; 
		//基地是否被占领
		bool is_captured=false; 
		//各lion的忠诚度
		std::map<int,int> lions_loyalty;    //前面的int为lion在所有兵里面的编号 
		//检查各狮子是否应该逃跑, 并让满足条件的狮子逃跑 
		virtual void check_lions_loyalty()=0; 
		//报告基地剩余生命元
		virtual void print3()=0;
		//按序列找到每个兵的情况
		std::map<int,warrior*> warriors_owning;
		//基地当前的生命元
		int Health; 
		// 根据Health初始化HQ类
		HQ(int Health,std::string troop_type,int city_serial,int HQ_flag);
		//兵种的排序方法
		virtual void next_troop()=0; 
		//初始化各兵种的血量
		virtual void init_troop_health(int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h);
		//初始化各兵种的攻击力
		virtual void init_troop_force(int dragon_f,int ninja_f,int iceman_f,int lion_f,int wolf_f); 
		//设置lion忠诚下降速率
		virtual void set_lion_loyalty_rate(int loyalty_rate);
};
class Blue_HQ:public HQ
{
	private:
		virtual void next_troop();	
		virtual void print1();
		virtual void print2();
	public:
		virtual void check_lions_loyalty(); 
		virtual void print3();
		Blue_HQ(int Health,int city_serial);
		friend class Procedure;
};
class Red_HQ:public HQ
{
	private:
		virtual void next_troop();
		virtual void print1();
		virtual void print2();
	public:
		virtual void check_lions_loyalty();
		virtual void print3();
		Red_HQ(int Health,int city_serial);
		friend class Procedure;		
};
class warrior;
class weapon
{
	protected: 
		warrior* owner;	   //武器的使用者 
		int force_rate;         //武器的攻击力占比 
	public:
		std::string name;       //武器的名字
		weapon(warrior* owner,int force_rate);	
		virtual int hit(warrior* owner,warrior* opponent)=0;
};
class sword:public weapon
{
	public: 
		sword(warrior* owner,int force_rate);
		int hit(warrior* owner,warrior* opponent);
};
class bomb:public weapon
{
	public:
		bomb(warrior* owner,int force_rate);
		int hit(warrior* owner,warrior* opponent);
};
class arrow:public weapon
{
	public:
		int time=2;
	public:
		arrow(warrior* owner,int force_rate);
		int hit(warrior* owner,warrior* opponent);
};
class city;
class weapon;
class HQ;
class warrior
{
	protected:
	public:
		std::vector<weapon*> weapons;
		HQ* HQ_belonged;
		int serial;
		std::string name;
		//武士所属阵营 
		color camp;
		//武士所属城市
		city* city_belonged; 
		int health;
		int force;  
		warrior(int serial,int health,int force,HQ* HQ_belonged,color camp);
		//介绍武士出生时的一些情况 
		virtual void print1();
		virtual int attack(warrior* opponent,weapon* w);
		//武士移动
		void warrior_move(city* new_city);
		//判断武士是否已经移动过
		bool round_finished=false; 
		//判断武器数量是否已满
		bool weapons_is_full();
		//从HQ删除这个武士
		void warrior_delete(); 
			
};
class dragon:public warrior
{
	private:
		double morale;
	public:
		dragon(int serial,int health,int force,HQ* HQ_belonged,color camp);	
};
class ninja:public warrior
{
	public:
		ninja(int serial,int health,int force,HQ* HQ_belonged,color camp);
		
};
class iceman:public warrior
{
	public:
		iceman(int serial,int health,int force,HQ* HQ_belonged,color camp);
};
class lion:public warrior
{
	public:
		int loyalty;
		lion(int serial,int health,int force,HQ* HQ_belonged,color camp);
};
class wolf:public warrior
{
	public:
		wolf(int serial,int health,int force,HQ* HQ_belonged,color camp);
		void rob_weapon(warrior* opponent,city* located_city);
};

city::city(int city_serial,int HQ_flag):city_serial(city_serial),HQ_flag(HQ_flag),redw(NULL),bluew(NULL),redw_Buff(NULL),bluew_Buff(NULL)
{
	
}
//武士到达 
void city::warrior_arrived(warrior* x)
{
	
	if(x->camp==red)
	{
		if(redw!=NULL)
		{
			redw_Buff=x;
		}
		else
		{
			redw=x;
		}
	}
	else
	{
		if(bluew!=NULL)
		{
			bluew_Buff=x;
		}
		else
		{
			bluew=x;
		}
	}
	//如果自己是基地，而有敌军来到 
	if(HQ_flag==-1||HQ_flag==1)
	{
		//判断蓝方基地 
		if(HQ_flag==1)
		{
			if(redw!=NULL)
			{
				//输出样例:001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
				print_now_time();
				cout<<"red "<<redw->name<<" "<<redw->serial<<" reached blue headquarter with "<<redw->health<<" elements and force "<<redw->force<<endl;
				HQ* temp=dynamic_cast<HQ*>(this);
				temp->is_captured=true;
			}
		}
		//判断红方基地 
		if(HQ_flag==-1)
		{
			if(bluew!=NULL)
			{
				//输出样例:001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
				print_now_time();
				cout<<"blue "<<bluew->name<<" "<<bluew->serial<<" reached red headquarter with "<<bluew->health<<" elements and force "<<bluew->force<<endl;
				HQ* temp=dynamic_cast<HQ*>(this);
				temp->is_captured=true;
			}
		}
	}
	//自己不是基地 
	else
	{
		print_now_time();
		cout<<(x->camp==red?"red ":"blue ")<<x->name<<" "<<x->serial<<" marched to city "<<city_serial<<" with "<<x->health<<" elements and force "<<x->force<<endl;
	}
	
	
}
//武士离开 
void city::warrior_left(warrior* x)
{
	if(x->camp==red)
	{
		if(redw_Buff==NULL)
		{
			redw=NULL;
		}
		else
		{
			redw=redw_Buff;
			redw_Buff=NULL;
		}
	}
	else
	{
		if(bluew_Buff==NULL)
		{
			bluew=NULL;	
		}
		else
		{
			bluew=bluew_Buff;
			bluew_Buff=NULL;
		}
	}	
}
//检查是否发生wolf抢夺武器
void city::check_rob()
{
	if(redw!=nullptr&&bluew!=nullptr)
	{
		if(redw->name=="wolf"&&bluew->name!="wolf")
		{
			wolf* rt=dynamic_cast<wolf*>(redw);
			rt->rob_weapon(bluew,this);
		}
		else if(redw->name!="wolf"&&bluew->name=="wolf")
		{
			wolf* bt=dynamic_cast<wolf*>(bluew);
			bt->rob_weapon(redw,this);
		}
	}
}
//检查是否能发生战斗 
void city::check_battle()
{
	if(redw&&bluew)   //发生战斗 
	{
		//给双方的武器排好序
		sort(redw->weapons.begin(),redw->weapons.end(),weapons_resort);
		sort(bluew->weapons.begin(),bluew->weapons.end(),weapons_resort);
		vector<weapon*>::iterator x1=redw->weapons.begin();
		vector<weapon*>::iterator x2=bluew->weapons.begin();
		//如果双方的血量在战斗中不再发生变化，则应让continue_battle为false 
		bool health_changed=true;
		//如果双方的武器都用完，则应让any_weapon_left为false 
		bool any_weapon_left;
		if((x1!=redw->weapons.end())||(x2!=bluew->weapons.end()))
		{
			any_weapon_left=true;
		} 
		else
		{
			any_weapon_left=false;
		}  
		//判断先手
		if(city_serial%2!=0)//红方先手 
		{
			while(redw&&bluew&&health_changed&&any_weapon_left)
			{
				int rh1=(redw->health);
				int bh1=(bluew->health);
				int status1=0,status2=0;
				if(x1!=redw->weapons.end())
				{
					status1=(redw->attack(bluew,*x1));
//					cout<<"调试：bluew->health="<<bluew->health<<endl;
				}
				if(x2!=bluew->weapons.end())
				{
					status2=(bluew->attack(redw,*x2));
//					cout<<"调试：redw->health="<<redw->health<<endl;
				}
				if(status1)
				{
					//删除这个武器
					vector<weapon*>::iterator x1t=x1;
					x1=redw->weapons.erase(x1t); 
				}
				else if(x1!=redw->weapons.end())
				{
					++x1;
				}
				else if(x1==redw->weapons.end())    //一轮武器用完
				{
					x1=redw->weapons.begin();	//x1重新指向开头 	
				} 
				if(status2)
				{
					//删除这个武器 
					vector<weapon*>::iterator x2t=x2;
					x2=bluew->weapons.erase(x2t);
				}
				else if(x2!=bluew->weapons.end())
				{
					++x2;
				}
				else if(x2==bluew->weapons.end())   //一轮武器用完 
				{
					x2=bluew->weapons.begin();      //x2重新指向开头 
				}
				//检测血条是否发生变化
				int rh2=(redw->health);
				int bh2=(bluew->health);
				if((rh1==rh2)&&(bh1==bh2))
				{
					health_changed==false;	
				}
				if(rh2<=0||bh2<=0)    //检测是否有人死去 
				{
					if(rh2<=0&&bh2<=0)    //同归于尽 
					{
						print_now_time();
						cout<<"both red "<<redw->name<<" "<<redw->serial<<" and blue "<<bluew->name<<" "<<bluew->serial<<" died in city "<<city_serial<<endl;
						redw->warrior_delete();
						bluew->warrior_delete();
						redw=nullptr; bluew=nullptr;		
					}
					else if(rh2>0&&bh2<=0)    //红方胜利 
					{ 
						//红方缴获蓝方武器
						sort(bluew->weapons.begin(),bluew->weapons.end(),weapons_resort_for_rob);
						while((!redw->weapons_is_full())&&(bluew->weapons.size()!=0)) 
						{
							vector<weapon*>::iterator temp=bluew->weapons.begin();
							redw->weapons.push_back(*temp);
							bluew->weapons.erase(temp);
						}
						print_now_time();
						cout<<"red "<<redw->name<<" "<<redw->serial<<" killed blue "<<bluew->name<<" "<<bluew->serial<<" in city "<<city_serial<<" remaining "<<redw->health<<" elements"<<endl;
						bluew->warrior_delete();
						bluew=nullptr;
					}
					else if(rh2<=0&&bh2>0)    //蓝方胜利
					{
						//蓝方缴获红方武器
						sort(redw->weapons.begin(),redw->weapons.end(),weapons_resort_for_rob); 
						while((!bluew->weapons_is_full())&&(redw->weapons.size()!=0)) 
						{
							vector<weapon*>::iterator temp=redw->weapons.begin();
							bluew->weapons.push_back(*temp);
							redw->weapons.erase(temp);
						}
						print_now_time();
						cout<<"blue "<<bluew->name<<" "<<bluew->serial<<" killed red "<<redw->name<<" "<<redw->serial<<" in city "<<city_serial<<" remaining "<<bluew->health<<" elements"<<endl;
						redw->warrior_delete();
						redw=nullptr;	
					}	
				} 
				//检测是否还有剩余武器 
				if(redw&&bluew)
				{ 
					if((redw->weapons.begin()!=redw->weapons.end())||(bluew->weapons.begin()!=bluew->weapons.end()))
					{
						any_weapon_left=true;
					} 
					else
					{
						any_weapon_left=false;
					}
				}		
			}
		}
		else				//蓝方先手 
		{
			while(redw&&bluew&&health_changed&&any_weapon_left)
			{
				int rh1=(redw->health);
				int bh1=(bluew->health);
				int status1=0,status2=0;
				if(x2!=bluew->weapons.end())
				{
					status2=(bluew->attack(redw,*x2));
//					cout<<"调试：redw->health="<<redw->health<<endl;
				}
				if(x1!=redw->weapons.end())
				{
					status1=(redw->attack(bluew,*x1));
//					cout<<"调试：bluew->health"<<bluew->health<<endl;
				}
				if(status1)
				{
					//删除这个武器
					vector<weapon*>::iterator x1t=x1;
					x1=redw->weapons.erase(x1t); 
				}
				else if(x1!=redw->weapons.end())
				{
					++x1;
				}
				else if(x1==redw->weapons.end())    //一轮武器用完
				{
					x1=redw->weapons.begin();	//x1重新指向开头 	
				} 
				if(status2)
				{
					//删除这个武器 
					vector<weapon*>::iterator x2t=x2;
					x2=bluew->weapons.erase(x2t);
				}
				else if(x2!=bluew->weapons.end())
				{
					++x2;
				}
				else if(x2==bluew->weapons.end())   //一轮武器用完 
				{
					x2=bluew->weapons.begin();      //x2重新指向开头 
				}
				//检测血条是否发生变化
				int rh2=(redw->health);
				int bh2=(bluew->health);
				if((rh1==rh2)&&(bh1==bh2))
				{
					health_changed==false;	
				}
				if(rh2<=0||bh2<=0)    //检测是否有人死去 
				{
					if(rh2<=0&&bh2<=0)    //同归于尽 
					{
						print_now_time();
						cout<<"both red "<<redw->name<<" "<<redw->serial<<" and blue "<<bluew->name<<" "<<bluew->serial<<" died in city "<<city_serial<<endl;
						redw->warrior_delete();
						bluew->warrior_delete();
						redw=nullptr; bluew=nullptr;		
					}
					else if(rh2>0&&bh2<=0)    //红方胜利 
					{
						//红方缴获蓝方武器
						sort(bluew->weapons.begin(),bluew->weapons.end(),weapons_resort_for_rob);
						while((!redw->weapons_is_full())&&(bluew->weapons.size()!=0)) 
						{
							vector<weapon*>::iterator temp=bluew->weapons.begin();
							redw->weapons.push_back(*temp);
							bluew->weapons.erase(temp);
						}
						print_now_time();
						cout<<"red "<<redw->name<<" "<<redw->serial<<" killed blue "<<bluew->name<<" "<<bluew->serial<<" in city "<<city_serial<<" remaining "<<redw->health<<" elements"<<endl;
						bluew->warrior_delete();
						bluew=nullptr;
					}
					else if(rh2<=0&&bh2>0)    //蓝方胜利
					{
						//蓝方缴获红方武器
						sort(redw->weapons.begin(),redw->weapons.end(),weapons_resort_for_rob); 
						while((!bluew->weapons_is_full())&&(redw->weapons.size()!=0)) 
						{
							vector<weapon*>::iterator temp=redw->weapons.begin();
							bluew->weapons.push_back(*temp);
							redw->weapons.erase(temp);
						}
						print_now_time();
						cout<<"blue "<<bluew->name<<" "<<bluew->serial<<" killed red "<<redw->name<<" "<<redw->serial<<" in city "<<city_serial<<" remaining "<<bluew->health<<" elements"<<endl;
						redw->warrior_delete();
						redw=nullptr;	
					}	
				} 
				//检测是否还有剩余武器
				if(redw&&bluew)
				{ 
					if((redw->weapons.begin()!=redw->weapons.end())||(bluew->weapons.begin()!=bluew->weapons.end()))
					{
						any_weapon_left=true;
					} 
					else
					{
						any_weapon_left=false;
					}
				}
			}	
		}
		
		//输出结果
		
		//首先检测有无阵亡(同归于尽、一方胜一方败)
		if(redw&&bluew)
		{
			//无人阵亡则输出结果
			print_now_time();
			cout<<"both red "<<redw->name<<" "<<redw->serial<<" and blue "<<bluew->name<<" "<<bluew->serial<<" were alive in city "<<city_serial<<endl;
		}
		 
	}
}
city::~city()
{
	
}
warrior* choose_worrior_by_name(string s,int serial,int health,int force,HQ* HQ_belonged,color camp)
{
	warrior* temp;
	if(s=="dragon")
	{
		temp=new dragon(serial,health,force,HQ_belonged,camp);
	}
	else if(s=="ninja")
	{
		temp=new ninja(serial,health,force,HQ_belonged,camp);
	}
	else if(s=="iceman")
	{
		temp=new iceman(serial,health,force,HQ_belonged,camp);
	}
	else if(s=="lion")
	{
		temp=new lion(serial,health,force,HQ_belonged,camp);
	}
	else if(s=="wolf")
	{
		temp=new wolf(serial,health,force,HQ_belonged,camp);
	}
	return temp;
}
weapon* choose_weapon_by_serial(int serial,warrior* owner)
{
	weapon* p=NULL;
	switch(serial)
	{
		case 0:
			p=new sword(owner,2);
			break;
		case 1:
			p=new bomb(owner,4);
			break;
		case 2:
			p=new arrow(owner,3);
			break;
	}
	return p;
}
//对武士所拥有的武器进行排序 
bool weapons_resort(weapon* a,weapon* b)
{
	if(a->name=="sword")
	{
		return true;
	}
	else if(a->name=="bomb")
	{
		if(b->name=="sword")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if(a->name=="arrow")
	{
		if(b->name!="arrow")
		{
			return false;
		}
		else
		{
			arrow* at=dynamic_cast<arrow*>(a);
			arrow* bt=dynamic_cast<arrow*>(b);
			if(at->time<=bt->time)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
bool weapons_resort_for_rob(weapon* a,weapon* b)
{
	if(a->name=="sword")
	{
		return true;
	}
	else if(a->name=="bomb")
	{
		if(b->name=="sword")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if(a->name=="arrow")
	{
		if(b->name!="arrow")
		{
			return false;
		}
		else
		{
			arrow* at=dynamic_cast<arrow*>(a);
			arrow* bt=dynamic_cast<arrow*>(b);
			if(at->time>=bt->time)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
void print_now_time()
{
	extern int now_time;
	int hour_temp=now_time/60;
	int minute_temp=now_time%60;
	cout.fill('0');cout.width(3);cout<<hour_temp<<":";
	cout.width(2);cout<<minute_temp<<" ";cout.fill(' ');
}
Procedure::Procedure(int Health,int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h,int dragon_f,int ninja_f,\
		int iceman_f,int lion_f,int wolf_f,int citys_num,int loyalty_rate,int total_time):Red(new Red_HQ(Health,0)),Blue(new Blue_HQ(Health,citys_num+1)),total_time(total_time),citys_num(citys_num)		
{
	Blue->init_troop_health(dragon_h,ninja_h,iceman_h,lion_h,wolf_h);
	Blue->init_troop_force(dragon_f,ninja_f,iceman_f,lion_f,wolf_f);
	Blue->set_lion_loyalty_rate(loyalty_rate);
	Red->init_troop_health(dragon_h,ninja_h,iceman_h,lion_h,wolf_h);
	Red->init_troop_force(dragon_f,ninja_f,iceman_f,lion_f,wolf_f);
	Red->set_lion_loyalty_rate(loyalty_rate);
	cities.insert(pair<int,city*>(0,Red));
	for(int i=1;i<=citys_num;++i)
	{
		cities.insert(pair<int,city*>(i,new city(i,0)));
	}
	cities.insert(pair<int,city*>(citys_num+1,Blue));
	
}
void Procedure::init_warrior_round_unfinished()
{
	map<int,warrior*>::iterator x;
	for(x=Red->warriors_owning.begin();x!=Red->warriors_owning.end();++x)
	{
		x->second->round_finished=false;
	}
	for(x=Blue->warriors_owning.begin();x!=Blue->warriors_owning.end();++x)
	{
		x->second->round_finished=false;
	}
}
//void Procedure::print_now_time(int hour_temp,int minute_temp)
//{
//	cout.fill('0');cout.width(3);cout<<hour_temp<<":";
//	cout.width(2);cout<<minute_temp<<" ";cout.fill(' ');
//}
void Procedure::begin()
{
	extern int now_time;
	while(now_time<=total_time)
	{
		events();
	}
}
void Procedure::events()
{
	extern int now_time;
	int hour_temp=now_time/60;
	int minute_temp=now_time%60;
	if(Red->is_captured==false&&Blue->is_captured==false)
	{
		switch(minute_temp)
		{
			case 0:
				Red->build_troop();
				Blue->build_troop();
				break;	
			case 5:
				//检查狮子是否忠诚小于等于0，是则逃跑
				//检查红方狮子
				Red->check_lions_loyalty();
				//检查蓝方狮子
				Blue->check_lions_loyalty(); 
				break;
			case 10:
				//从西向东遍历所有城市的武士移动事件 
				init_warrior_round_unfinished();
				for(int i=0;i<citys_num+2;++i)
				{
					if((cities[i]->redw)||(cities[i]->bluew))
					{
						warrior* temp;
						if(cities[i]->redw&&!(cities[i]->redw->round_finished))
						{
							temp=cities[i]->redw;
							//改变城市中的武士 
							cities[i]->warrior_left(temp);
							//改变武士所属城市,并输出相关信息 
							(temp)->warrior_move(cities[i+1]);
							//改变城市中的武士 
							cities[i+1]->warrior_arrived(temp);
						}
						if(cities[i]->bluew&&!(cities[i]->bluew->round_finished))
						{
							temp=cities[i]->bluew;
							//改变城市中的武士 
							cities[i]->warrior_left(temp);
							//改变武士所属城市,并输出相关信息 
							(temp)->warrior_move(cities[i-1]);
							//改变城市中的武士 
							cities[i-1]->warrior_arrived(temp);	
						}	
					}	
				}
				break;
			case 35:
				//遍历每个城市检查是否发生武器抢夺
				for(int i=0;i<citys_num+2;++i)
				{
					cities[i]->check_rob();	
				} 
				break;
			case 40:
				//遍历每个城市检查是否发生战斗
				for(int i=0;i<citys_num+2;++i)
				{
					cities[i]->check_battle();	
				}
				break;
			case 50:
				//红方基地报告生命元 
				Red->print3();
				//蓝方基地报告生命元
				Blue->print3(); 
				break;
			case 55:      //武士报告情况
				//红方所有武士
				for(map<int,warrior*>::iterator x=(Red->warriors_owning.begin());x!=(Red->warriors_owning.end());++x)
				{
					x->second->print1();	
				}
				//蓝方所有武士
				for(map<int,warrior*>::iterator x=(Blue->warriors_owning.begin());x!=(Blue->warriors_owning.end());++x)
				{
					x->second->print1();	
				} 
				break;
			default:
				//无事发生
				break;
		}
	}
	now_time+=5; 

}
void HQ::build_troop()
{
	if(is_producting)
	{
		int cnt=0;
		while((troop_health[now_troop]>Health)&&(cnt!=troop_health.size()))      //判断能不能再产兵 
		{
			next_troop();
			cnt++;
		}
		if(cnt!=troop_health.size())
		{
//			troop_num[now_troop]++;
			warriors_owning.insert(pair<int,warrior*>(serial,choose_worrior_by_name(now_troop,serial,troop_health[now_troop],troop_force[now_troop],this,camp)));
			Health-=troop_health[now_troop];
			//武士出生在本城市（HQ算作一个城市） 
			warrior_arrived(warriors_owning[serial]);
			print_now_time();
			print1();
			serial++;
			next_troop();	
		}
		else
		{
			is_producting=false;
			print_now_time();
			print2();
		}
	}	
}
HQ::HQ(int Health,string troop_type,int city_serial,int HQ_flag):Health(Health),now_troop(troop_type),city(city_serial,HQ_flag)
{	
} 
void HQ::init_troop_health(int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h)
{
	troop_health.insert(pair<string,int>("dragon",dragon_h));
	troop_health.insert(pair<string,int>("ninja",ninja_h));
	troop_health.insert(pair<string,int>("iceman",iceman_h));
	troop_health.insert(pair<string,int>("lion",lion_h));
	troop_health.insert(pair<string,int>("wolf",wolf_h));
}
void HQ::init_troop_force(int dragon_f,int ninja_f,int iceman_f,int lion_f,int wolf_f)
{
	troop_force.insert(pair<string,int>("dragon",dragon_f));
	troop_force.insert(pair<string,int>("ninja",ninja_f));
	troop_force.insert(pair<string,int>("iceman",iceman_f));
	troop_force.insert(pair<string,int>("lion",lion_f));
	troop_force.insert(pair<string,int>("wolf",wolf_f));
}
void HQ::set_lion_loyalty_rate(int loyalty_rate)
{
	this->loyalty_rate=loyalty_rate;
} 
void Blue_HQ::next_troop()
{
	if (now_troop=="lion")
	{
		now_troop="dragon";
	}
	else if(now_troop=="dragon")
	{
		now_troop="ninja";
	}
	else if(now_troop=="ninja")
	{
		now_troop="iceman";
	}
	else if(now_troop=="iceman")
	{
		now_troop="wolf";
	}
	else if(now_troop=="wolf")
	{
		now_troop="lion";
	}
}
//报告武士出生	
void Blue_HQ::print1()
{
	cout<<"blue "<<now_troop<<" "<<serial<<" "<<"born"<<endl;
	if(now_troop=="lion")
	{
		cout<<"Its loyalty is "<<lions_loyalty[serial]<<endl;
	}
} 
void Blue_HQ::print2()
{
	cout<<"blue headquarter stops making warriors"<<endl;	
}	
Blue_HQ::Blue_HQ(int Health,int city_serial):HQ(Health,"lion",city_serial,1)
{
	camp=blue;
}
void Blue_HQ::print3()
{
	print_now_time();
	cout<<Health<<" elements in blue headquarter"<<endl;
}
void Blue_HQ::check_lions_loyalty()
{
	map<int,int>::iterator x;
	for(x=lions_loyalty.begin();x!=lions_loyalty.end();++x)
	{
		if(x->second<=0)
		{
			print_now_time();
			cout<<"blue lion "<<x->first<<" ran away"<<endl;
			//lion's city
			warriors_owning[x->first]->city_belonged->bluew=NULL;
			//warriors_owning
			map<int,warrior*>::iterator temp1=warriors_owning.find(x->first);
			warriors_owning.erase(temp1);
			//lions_loyalty
			lions_loyalty.erase(x);		
		}	
	} 
}
void Red_HQ::next_troop()
{
	if (now_troop=="iceman")
	{
		now_troop="lion";
	}
	else if(now_troop=="lion")
	{
		now_troop="wolf";
	}
	else if(now_troop=="wolf")
	{
		now_troop="ninja";
	}
	else if(now_troop=="ninja")
	{
		now_troop="dragon";
	}
	else if(now_troop=="dragon")
	{
		now_troop="iceman";
	}	
}
void Red_HQ::print1()
{
	cout<<"red "<<now_troop<<" "<<serial<<" "<<"born"<<endl;
	if(now_troop=="lion")
	{
		cout<<"Its loyalty is "<<lions_loyalty[serial]<<endl;
	}
} 
void Red_HQ::print2()
{
	cout<<"red headquarter stops making warriors"<<endl;	
}
void Red_HQ::print3()
{
	print_now_time();
	cout<<Health<<" elements in red headquarter"<<endl;
}
void Red_HQ::check_lions_loyalty()
{
	map<int,int>::iterator x;
	for(x=lions_loyalty.begin();x!=lions_loyalty.end();++x)
	{
		if(x->second<=0)
		{
			print_now_time();
			cout<<"red lion "<<x->first<<" ran away"<<endl;
			//lion's city
			warriors_owning[x->first]->city_belonged->redw=NULL;
			//warriors_owning
			map<int,warrior*>::iterator temp1=warriors_owning.find(x->first);
			warriors_owning.erase(temp1);
			//lions_loyalty
			lions_loyalty.erase(x);		
		}	
	} 
}
Red_HQ::Red_HQ(int Health,int city_serial):HQ(Health,"iceman",city_serial,-1)
{
	camp=red;	
}
weapon::weapon(warrior* owner,int force_rate):owner(owner),force_rate(force_rate)
{
		
}
sword::sword(warrior* owner,int force_rate):weapon(owner,force_rate)
{
	this->name="sword";
}
int sword::hit(warrior* owner,warrior* opponent)
{
	(opponent->health)-=((owner->force)*force_rate/10);
	return 0;
}
bomb::bomb(warrior* owner,int force_rate):weapon(owner,force_rate)
{
	this->name="bomb";
}
int bomb::hit(warrior* owner,warrior* opponent)
{
//	cout<<"调试：Before bomb explosed,owner: "<<(owner->camp==red?"red":"blue")<<" "<<owner->name<<"'s heatlh is "<<owner->health<<endl;
	(opponent->health)-=((owner->force)*force_rate/10);
	if(owner->name!="ninja")   //忍者特性 
	{
		(owner->health)-=((static_cast<int>(opponent->force)*5/10));
	}
//	cout<<"调试：After bomb explosed,owner: "<<(owner->camp==red?"red":"blue")<<" "<<owner->name<<"'s heatlh is "<<owner->health<<endl;
	return 1;
}
arrow::arrow(warrior* owner,int force_rate):weapon(owner,force_rate)
{
	this->name="arrow";
}
int arrow::hit(warrior* owner,warrior* opponent)        //返回1代表arrow已经花完所用次数 
{
	(opponent->health)-=((owner->force)*force_rate/10);
	time--;
	if(time==0)
		return 1;
	else
		return 0;
}
warrior::warrior(int serial,int health,int force,HQ* HQ_belonged,color camp):serial(serial),health(health),force(force),HQ_belonged(HQ_belonged),camp(camp),city_belonged(HQ_belonged)
{
}
//报告武士武器状况 
void warrior::print1()
{
	int s_n,b_n,a_n;
	sort(weapons.begin(),weapons.end(),weapons_resort);
	vector<weapon*>::iterator x1=weapons.begin();
	vector<weapon*>::iterator x2;
	while(x1!=weapons.end()&&((*x1)->name=="sword"))
	{
		++x1;
	}
	s_n=x1-weapons.begin();
	x2=x1;
	while(x2!=weapons.end()&&((*x2)->name=="bomb"))
	{
		++x2;
	}
	b_n=x2-x1;
	a_n=weapons.end()-x2;
	print_now_time();
	cout<<(camp==red?"red":"blue")<<" "<<name<<" "<<serial<<" has "<<s_n<<" sword "<<b_n<<" bomb "<<a_n<<" arrow and "<<health<<" elements"<<endl;
}
int warrior::attack(warrior* opponent,weapon* w)     
{
	return (w->hit(this,opponent));
}
void warrior::warrior_move(city* new_city)
{
	city* old_city=city_belonged;
	city_belonged=new_city;
	if(name=="iceman")
	{
		health-=(health/10);
	}
	if(name=="lion")
	{
		lion* temp=dynamic_cast<lion*>(this);
		temp->loyalty-=temp->HQ_belonged->loyalty_rate;
		//改变HQ的loyalty_map 
		(temp->HQ_belonged->lions_loyalty)[temp->serial]=temp->loyalty;
	}
//	print_now_time();
//	cout<<(camp==red?"red ":"blue ")<<name<<" "<<serial<<" marched to city "<<new_city->city_serial<<" with "<<health<<" elements and force "<<force<<endl;
	round_finished=true;
}
bool warrior::weapons_is_full()
{
	if(weapons.size()==10)
		return true;
	else
		return false;	
}
void warrior::warrior_delete()
{
	//HQ的lions_loyalty 
	if(name=="lion")
	{
		map<int,int>::iterator temp=(HQ_belonged->lions_loyalty).find(serial);
		(HQ_belonged->lions_loyalty).erase(temp);
	}
	//HQ的warriors_owning
	map<int,warrior*>::iterator temp1=(HQ_belonged->warriors_owning).find(serial);
	(HQ_belonged->warriors_owning).erase(temp1);	
} 
dragon::dragon(int serial,int health,int force,HQ* HQ_belonged,color camp):warrior(serial,health,force,HQ_belonged,camp),morale((HQ_belonged->Health-health)*1.0/health)
{
	name="dragon";
	//龙获得武器 
	weapons.push_back(choose_weapon_by_serial(serial%3,this));
	
}
ninja::ninja(int serial,int health,int force,HQ* HQ_belonged,color camp):warrior(serial,health,force,HQ_belonged,camp)
{
	name="ninja";
	//忍者获得武器
	 weapons.push_back(choose_weapon_by_serial(serial%3,this));
	 weapons.push_back(choose_weapon_by_serial((serial+1)%3,this));
}
iceman::iceman(int serial,int health,int force,HQ* HQ_belonged,color camp):warrior(serial,health,force,HQ_belonged,camp)
{
	name="iceman";
	//冰人获得武器
	 weapons.push_back(choose_weapon_by_serial(serial%3,this));
}
lion::lion(int serial,int health,int force,HQ* HQ_belonged,color camp):warrior(serial,health,force,HQ_belonged,camp),loyalty(HQ_belonged->Health-health)
{
	name="lion";
	weapons.push_back(choose_weapon_by_serial(serial%3,this));
	HQ_belonged->lions_loyalty.insert(pair<int,int>(serial,loyalty));
}
wolf::wolf(int serial,int health,int force,HQ* HQ_belonged,color camp):warrior(serial,health,force,HQ_belonged,camp)
{	
	name="wolf";
}
void wolf::rob_weapon(warrior* opponent,city* located_city)
{
	if(opponent->name!="wolf")//若敌人是wolf，则不抢武器
	{
		if((opponent->weapons.begin())!=(opponent->weapons.end()))//若敌人没有武器，则不抢 
		{ 
			sort(opponent->weapons.begin(),opponent->weapons.end(),weapons_resort_for_rob);
			vector<weapon*>::iterator x=opponent->weapons.begin();
			string weapon_name=((*x)->name);   //抢夺武器的名字 
			int cnt=0;    //抢夺武器的数量 
			while((!weapons_is_full())&&(x!=opponent->weapons.end())&&((*x)->name==weapon_name))
			{
				weapon* temp=(*x);
				vector<weapon*>::iterator xt=x;
				x=(opponent->weapons).erase(xt);
				weapons.push_back(temp);
				cnt++;
			}
			if(cnt!=0)
			{
				print_now_time();
				cout<<(camp==red?"red ":"blue ")<<name<<" "<<serial<<" took "<<cnt<<" "<<weapon_name<<" from "\
				<<((opponent->camp)==red?"red ":"blue ")<<opponent->name<<" "<<opponent->serial<<" in city "<<located_city->city_serial<<endl;	
			}
		}
	}
}
//输入格式:
//第一行代表游戏局数
//第二行依次代表双方基地生命元、基地之间有多少个城市、lion每前进一步其忠诚降低的数目，以及一局游戏的最高时长（分钟为单位）
//第三行依次代表dragon 、ninja、iceman、lion、wolf的生命元
//第四行依次代表dragon 、ninja、iceman、lion、wolf的攻击力 
int main()
{
	int n;
	int v,c,k,T;
	int v1,v2,v3,v4,v5;
	int f1,f2,f3,f4,f5;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		now_time=0;
		cin>>v;
		cin>>c>>k>>T;
		cin>>v1>>v2>>v3>>v4>>v5;
		cin>>f1>>f2>>f3>>f4>>f5;
		cout<<"Case:"<<i<<endl;
		Procedure p(v,v1,v2,v3,v4,v5,f1,f2,f3,f4,f5,c,k,T);
		p.begin();
	}  
	return 0;
}
