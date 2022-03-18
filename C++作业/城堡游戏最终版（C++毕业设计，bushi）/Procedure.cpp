#include "Procedure.h"
#include "HQ.h"
#include <iostream>
#include "other_functions.h"
#include <map>
using namespace std;


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
//void Procedure::begin()
//{
//	while(Red->is_producting||Blue->is_producting)
//	{
//		Red->build_troop(now_time);
//		Blue->build_troop(now_time);
//		now_time++;
//	}
//}
