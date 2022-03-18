#ifndef __HQ_H__
#define __HQ_H__
#include <map>
#include <string>
#include "warrior.h"
#include "city.h"
//#include "Procedure.h"
class warrior; 
class HQ:public city
{
	protected:
		//阵营（红蓝）
		color camp; 
		//基地当前将要制造的兵种
		std::string now_troop; 
		//下一个要生产的兵种的编号
		int serial=1; 
		//基地当前是否还在产兵
		bool is_producting=true; 
//		//各类兵种的数量 
//		std::map<std::string,int> troop_num;
		//各类兵种的生命值
		std::map<std::string,int> troop_health;
		//各类兵种的攻击力
		std::map<std::string,int> troop_force;
		//要打印的信息:
		//报告武士出生 
		virtual void print1()=0;
		//宣布停止造兵 
		virtual void print2()=0; 
		//造兵的方法 
		void build_troop(); 
	public:
		//lion忠诚度的下降速度
		int loyalty_rate; 
		//基地是否被占领
		bool is_captured=false; 
		//各lion的忠诚度
		std::map<int,int> lions_loyalty;    //前面的int为lion在所有兵里面的编号 
		//检查各狮子是否应该逃跑, 并让满足条件的狮子逃跑 
		virtual void check_lions_loyalty()=0; 
		//报告基地剩余生命元
		virtual void print3()=0;
		//按序列找到每个兵的情况
		std::map<int,warrior*> warriors_owning;
		//基地当前的生命元
		int Health; 
		// 根据Health初始化HQ类
		HQ(int Health,std::string troop_type,int city_serial,int HQ_flag);
		//兵种的排序方法
		virtual void next_troop()=0; 
		//初始化各兵种的血量
		virtual void init_troop_health(int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h);
		//初始化各兵种的攻击力
		virtual void init_troop_force(int dragon_f,int ninja_f,int iceman_f,int lion_f,int wolf_f); 
		//设置lion忠诚下降速率
		virtual void set_lion_loyalty_rate(int loyalty_rate);
};
class Blue_HQ:public HQ
{
	private:
		virtual void next_troop();	
		virtual void print1();
		virtual void print2();
	public:
		virtual void check_lions_loyalty(); 
		virtual void print3();
		Blue_HQ(int Health,int city_serial);
		friend class Procedure;
};
class Red_HQ:public HQ
{
	private:
		virtual void next_troop();
		virtual void print1();
		virtual void print2();
	public:
		virtual void check_lions_loyalty();
		virtual void print3();
		Red_HQ(int Health,int city_serial);
		friend class Procedure;		
};
#endif
