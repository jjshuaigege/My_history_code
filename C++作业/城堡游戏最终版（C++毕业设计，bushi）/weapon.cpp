#include "weapon.h"
#include "warrior.h"
#include <iostream>
//#include "warrior.h" 
using namespace std;
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
	cout<<"调试：Before bomb explosed,owner: "<<(owner->camp==red?"red":"blue")<<" "<<owner->name<<"'s heatlh is "<<owner->health<<endl;
	(opponent->health)-=((owner->force)*force_rate/10);
	if(owner->name!="ninja")   //忍者特性 
	{
		(owner->health)-=((static_cast<int>(opponent->force)*5/10));
	}
	cout<<"调试：After bomb explosed,owner: "<<(owner->camp==red?"red":"blue")<<" "<<owner->name<<"'s heatlh is "<<owner->health<<endl;
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
