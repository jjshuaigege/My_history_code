#ifndef __CITY_H__
#define __CITY_H__
class warrior;
class city
{
	private:
		warrior* redw_Buff;
		warrior* bluew_Buff;
		//-1代表红方基地，0代表正常城市,1代表蓝方基地 
		int HQ_flag;
	public:
		warrior* redw;
		warrior* bluew;
		int city_serial;
		city(int city_serial,int HQ_flag);
		//武士到达 
		void warrior_arrived(warrior* x);
		//武士离开 
		void warrior_left(warrior* x);
		//检查是否发生wolf抢夺武器
		void check_rob(); 
		//检查是否能发生战斗 
		void check_battle();
		friend class Procedure;
		virtual ~city();
};
#endif
