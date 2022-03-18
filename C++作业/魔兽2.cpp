#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
class warrior;
class HQ;
warrior* choose_worrior_by_name(string s,int serial,int health,HQ* HQ_belonged);
class weapon
{
	protected: 
		warrior* owner;	   //武器的使用者 
		int force;         //武器的攻击力
	public:
		string name;       //武器的名字
		weapon(warrior* owner):owner(owner)
		{
				
		}	
};
class sword:public weapon
{
	public: 
		sword(warrior* owner):weapon(owner)
		{
			this->name="sword";
		}
};
class bomb:public weapon
{
	public:
		bomb(warrior* owner):weapon(owner)
		{
			this->name="bomb";
		}
};
class arrow:public weapon
{
	public:
		arrow(warrior* owner):weapon(owner)
		{
			this->name="arrow";
		}
};
weapon* choose_weapon_by_serial(int serial,warrior* owner)
{
	weapon* p=NULL;
	switch(serial)
	{
		case 0:
			p=new sword(owner);
			break;
		case 1:
			p=new bomb(owner);
			break;
		case 2:
			p=new arrow(owner);
			break;
	}
	return p;
}
class warrior
{
	protected:
		//武士编号 
		int serial;
		//武士生命值 
		int health;
		//武士所拥有的武器 
		vector<weapon*> weapons;
		//武士所属的阵营
		HQ* HQ_belonged; 
		
	public:
		warrior(int serial,int health,HQ* HQ_belonged):serial(serial),health(health),HQ_belonged(HQ_belonged)
		{	
		}
		//介绍武士出生时的一些情况 
		virtual void print1()=0;	
};
class HQ
{
	protected:
		//基地当前将要制造的兵种
		string now_troop; 
		//下一个要生产的兵种的编号
		int serial=1; 
		//基地当前是否还在产兵
		bool is_producting=true;
		//按序列找到每个兵的情况
		map<int,warrior*> warriors_owning; 
		//各类兵种的数量 
		map<string,int> troop_num;
		//各类兵种的生命值
		map<string,int> troop_health;
		//要打印的信息
		virtual void print1()=0;
		virtual void print2()=0;
		//造兵的方法 
		void build_troop(int now_time)
		{
			if(is_producting)
			{
				int cnt=0;
				printf("%03d ",now_time);
				while((troop_health[now_troop]>Health)&&(cnt!=troop_health.size()))      //判断能不能再产兵 
				{
					next_troop();
					cnt++;
				}
				if(cnt!=troop_health.size())
				{
					troop_num[now_troop]++;
					warriors_owning.insert(pair<int,warrior*>(serial,choose_worrior_by_name(now_troop,serial,troop_health[now_troop],this)));
					Health-=troop_health[now_troop];
					print1();
					//介绍当武士出生的时候，出于武士种类而不同的一些具体情况 
					warriors_owning[serial]->print1();
					serial++;
					next_troop();	
				}
				else
				{
					is_producting=false;
					print2();
				}
			}	
		}
	public:
		//基地当前的生命元
		int Health; 
		// 根据Health初始化HQ类
		HQ(int Health,string troop_type):Health(Health),now_troop(troop_type)
		{	
		} 
		//兵种的排序方法
		virtual void next_troop()=0; 
		//定义各兵种的血量
		virtual void init_troop_health(int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h)
		{
			troop_health.insert(pair<string,int>("dragon",dragon_h));
			troop_health.insert(pair<string,int>("ninja",ninja_h));
			troop_health.insert(pair<string,int>("iceman",iceman_h));
			troop_health.insert(pair<string,int>("lion",lion_h));
			troop_health.insert(pair<string,int>("wolf",wolf_h));
		}
};
class dragon:public warrior
{
	private:
		double morale;
	public:
		dragon(int serial,int health,HQ* HQ_belonged):warrior(serial,health,HQ_belonged),morale((HQ_belonged->Health-health)*1.0/health)
		{
			//龙获得武器 
			weapons.push_back(choose_weapon_by_serial(serial%3,this));
			
		}
		void print1()
		{
			cout<<"It has a "<<weapons.at(0)->name<<",and it's morale is ";
			printf("%.2f",morale);
			cout<<endl;	
		}	
};
class ninja:public warrior
{
	public:
		ninja(int serial,int health,HQ* HQ_belonged):warrior(serial,health,HQ_belonged)
		{
			//忍者获得武器
			 weapons.push_back(choose_weapon_by_serial(serial%3,this));
			 weapons.push_back(choose_weapon_by_serial((serial+1)%3,this));
		}
		void print1()
		{
			cout<<"It has a "<<weapons.at(0)->name<<" and a "<<weapons.at(1)->name<<endl;
		}
		
};
class iceman:public warrior
{
	public:
		iceman(int serial,int health,HQ* HQ_belonged):warrior(serial,health,HQ_belonged)
			{
				//冰人获得武器
				 weapons.push_back(choose_weapon_by_serial(serial%3,this));
			}
		void print1()
		{
			cout<<"It has a "<<weapons.at(0)->name<<endl;
		}
};
class lion:public warrior
{
	private:
		int loyalty;
	public:
		lion(int serial,int health,HQ* HQ_belonged):warrior(serial,health,HQ_belonged),loyalty(HQ_belonged->Health-health)
		{
			
		}
		void print1()
		{
			cout<<"It's loyalty is "<<loyalty<<endl;
		}
};
class wolf:public warrior
{
	public:
		wolf(int serial,int health,HQ* HQ_belonged):warrior(serial,health,HQ_belonged)
		{
			
		}
		void print1()
		{
		}
};
warrior* choose_worrior_by_name(string s,int serial,int health,HQ* HQ_belonged)
{
	warrior* temp;
	if(s=="dragon")
	{
		temp=new dragon(serial,health,HQ_belonged);
	}
	else if(s=="ninja")
	{
		temp=new ninja(serial,health,HQ_belonged);
	}
	else if(s=="iceman")
	{
		temp=new iceman(serial,health,HQ_belonged);
	}
	else if(s=="lion")
	{
		temp=new lion(serial,health,HQ_belonged);
	}
	else if(s=="wolf")
	{
		temp=new wolf(serial,health,HQ_belonged);
	}
	return temp;
}
class Blue_HQ:public HQ
{
	private:
		virtual void next_troop()
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
		virtual void print1()
		{
			cout<<"blue "<<now_troop<<" "<<serial<<" "<<"born with strength "<<troop_health[now_troop]<<","<<\
			troop_num[now_troop]<<" "<<now_troop<<" in blue headquarter"<<endl;
		} 
		virtual void print2()
		{
			cout<<"blue headquarter stops making warriors"<<endl;	
		}	
	public:
		Blue_HQ(int Health):HQ(Health,"lion")
		{
		}
		friend class Procedure;
};
class Red_HQ:public HQ
{
	private:
		virtual void next_troop()
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
		virtual void print1()
		{
			cout<<"red "<<now_troop<<" "<<serial<<" "<<"born with strength "<<troop_health[now_troop]<<","\
			<<troop_num[now_troop]<<" "<<now_troop<<" in red headquarter"<<endl;
		} 
		virtual void print2()
		{
			cout<<"red headquarter stops making warriors"<<endl;	
		}	
	public:
		Red_HQ(int Health):HQ(Health,"iceman")
		{	
		}
		friend class Procedure;	
};
class Procedure
{
	private:
		int now_time=0;
		Red_HQ* Red;
		Blue_HQ* Blue;
	public:
		Procedure(int Health,int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h):Red(new Red_HQ(Health)),Blue(new Blue_HQ(Health))
		{
			Red->init_troop_health(dragon_h,ninja_h,iceman_h,lion_h,wolf_h);
			Blue->init_troop_health(dragon_h,ninja_h,iceman_h,lion_h,wolf_h);
		}
		void begin()
		{
			while(Red->is_producting||Blue->is_producting)
			{
				Red->build_troop(now_time);
				Blue->build_troop(now_time);
				now_time++;
			}
		}
};
int main()
{
	int n,v,v1,v2,v3,v4,v5;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>v;
		cin>>v1>>v2>>v3>>v4>>v5;
		cout<<"Case:"<<i<<endl;
		Procedure p(v,v1,v2,v3,v4,v5);
		p.begin();
	}
	return 0;
}
