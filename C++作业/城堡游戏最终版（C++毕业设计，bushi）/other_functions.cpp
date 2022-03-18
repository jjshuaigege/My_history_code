#include "other_functions.h"
#include "HQ.h"
#include "warrior.h"
#include "weapon.h"
#include <iostream>
using namespace std;
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
