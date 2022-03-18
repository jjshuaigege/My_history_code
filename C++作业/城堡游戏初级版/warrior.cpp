#include "warrior.h"
#include "HQ.h"
#include "other_functions.h"
#include "weapon.h"
#include <iostream>
#include <algorithm>
using namespace std;
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
		health-=(int)(health*0.1);
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
