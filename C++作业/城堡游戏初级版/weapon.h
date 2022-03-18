#ifndef __WEAPON_H__
#define __WEAPON_H__
#include <string>
class warrior;
class weapon
{
	protected: 
		warrior* owner;	   //������ʹ���� 
		int force_rate;         //�����Ĺ�����ռ�� 
	public:
		std::string name;       //����������
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
#endif
