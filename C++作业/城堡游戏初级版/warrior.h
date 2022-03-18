#ifndef _WARRIOR_H_
#define _WARRIOR_H_
#include <vector>
#include <string>
class city;
class weapon;
enum color{red,blue};
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
#endif
