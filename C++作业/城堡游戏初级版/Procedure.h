#ifndef __PROCEDURE_H__
#define __PROCEDURE_H__
#include <map>
class Red_HQ;
class Blue_HQ;
class city;
class Procedure
{
	private:
		int total_time;
		std::map<int,city*> cities;
		int citys_num;
		Red_HQ* Red;
		Blue_HQ* Blue;
		void init_warrior_round_unfinished();
	public:
		Procedure(int Health,int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h,int dragon_f,int ninja_f,\
		int iceman_f,int lion_f,int wolf_f,int citys_num,int loyalty_rate,int total_time);
		void begin();
		void events();
};
#endif
