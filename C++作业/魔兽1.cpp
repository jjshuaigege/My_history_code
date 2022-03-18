#include <iostream>
#include <map>
#include <string>
using namespace std;
class HQ
{
	protected:
		//基地当前的生命元
		int Health; 
		//基地当前将要制造的兵种
		string now_troop; 
		//下一个要生产的兵种的编号
		int serial=1; 
		//基地当前是否还在产兵
		bool is_producting=true; 
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
				while((troop_health[now_troop]>Health)&&(cnt!=troop_health.size()))      //不能再产兵了 
				{
					next_troop();
					cnt++;
				}
				if(cnt!=troop_health.size())
				{
					troop_num[now_troop]++;
					Health-=troop_health[now_troop];
					print1();
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
		cout<<"case:"<<i<<endl;
		Procedure p(v,v1,v2,v3,v4,v5);
		p.begin();
	}
	return 0;
}

