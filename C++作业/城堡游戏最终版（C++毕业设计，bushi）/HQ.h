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
		//��Ӫ��������
		color camp; 
		//���ص�ǰ��Ҫ����ı���
		std::string now_troop; 
		//��һ��Ҫ�����ı��ֵı��
		int serial=1; 
		//���ص�ǰ�Ƿ��ڲ���
		bool is_producting=true; 
//		//������ֵ����� 
//		std::map<std::string,int> troop_num;
		//������ֵ�����ֵ
		std::map<std::string,int> troop_health;
		//������ֵĹ�����
		std::map<std::string,int> troop_force;
		//Ҫ��ӡ����Ϣ:
		//������ʿ���� 
		virtual void print1()=0;
		//����ֹͣ��� 
		virtual void print2()=0; 
		//����ķ��� 
		void build_troop(); 
	public:
		//lion�ҳ϶ȵ��½��ٶ�
		int loyalty_rate; 
		//�����Ƿ�ռ��
		bool is_captured=false; 
		//��lion���ҳ϶�
		std::map<int,int> lions_loyalty;    //ǰ���intΪlion�����б�����ı�� 
		//����ʨ���Ƿ�Ӧ������, ��������������ʨ������ 
		virtual void check_lions_loyalty()=0; 
		//�������ʣ������Ԫ
		virtual void print3()=0;
		//�������ҵ�ÿ���������
		std::map<int,warrior*> warriors_owning;
		//���ص�ǰ������Ԫ
		int Health; 
		// ����Health��ʼ��HQ��
		HQ(int Health,std::string troop_type,int city_serial,int HQ_flag);
		//���ֵ����򷽷�
		virtual void next_troop()=0; 
		//��ʼ�������ֵ�Ѫ��
		virtual void init_troop_health(int dragon_h,int ninja_h,int iceman_h,int lion_h,int wolf_h);
		//��ʼ�������ֵĹ�����
		virtual void init_troop_force(int dragon_f,int ninja_f,int iceman_f,int lion_f,int wolf_f); 
		//����lion�ҳ��½�����
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
