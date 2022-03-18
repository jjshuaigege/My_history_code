#include <iostream>
#include "HQ.h"
#include "other_functions.h"
#include "warrior.h"
using namespace std;
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
		cout<<"It's loyalty is "<<lions_loyalty[serial]<<endl;
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
