#ifndef __CITY_H__
#define __CITY_H__
class warrior;
class city
{
	private:
		warrior* redw_Buff;
		warrior* bluew_Buff;
		//-1����췽���أ�0������������,1������������ 
		int HQ_flag;
	public:
		warrior* redw;
		warrior* bluew;
		int city_serial;
		city(int city_serial,int HQ_flag);
		//��ʿ���� 
		void warrior_arrived(warrior* x);
		//��ʿ�뿪 
		void warrior_left(warrior* x);
		//����Ƿ���wolf��������
		void check_rob(); 
		//����Ƿ��ܷ���ս�� 
		void check_battle();
		friend class Procedure;
		virtual ~city();
};
#endif
