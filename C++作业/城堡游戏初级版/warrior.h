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
		//��ʿ������Ӫ 
		color camp;
		//��ʿ��������
		city* city_belonged; 
		int health;
		int force;  
		warrior(int serial,int health,int force,HQ* HQ_belonged,color camp);
		//������ʿ����ʱ��һЩ��� 
		virtual void print1();
		virtual int attack(warrior* opponent,weapon* w);
		//��ʿ�ƶ�
		void warrior_move(city* new_city);
		//�ж���ʿ�Ƿ��Ѿ��ƶ���
		bool round_finished=false; 
		//�ж����������Ƿ�����
		bool weapons_is_full();
		//��HQɾ�������ʿ
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
