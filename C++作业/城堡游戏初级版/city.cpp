#include "city.h"
#include "warrior.h"
#include <iostream>
#include "other_functions.h"
#include "HQ.h"
#include <algorithm>
using namespace std;
city::city(int city_serial,int HQ_flag):city_serial(city_serial),HQ_flag(HQ_flag),redw(NULL),bluew(NULL),redw_Buff(NULL),bluew_Buff(NULL)
{
	
}
//��ʿ���� 
void city::warrior_arrived(warrior* x)
{
	
	if(x->camp==red)
	{
		if(redw!=NULL)
		{
			redw_Buff=x;
		}
		else
		{
			redw=x;
		}
	}
	else
	{
		if(bluew!=NULL)
		{
			bluew_Buff=x;
		}
		else
		{
			bluew=x;
		}
	}
	//����Լ��ǻ��أ����ео����� 
	if(HQ_flag==-1||HQ_flag==1)
	{
		//�ж��������� 
		if(HQ_flag==1)
		{
			if(redw!=NULL)
			{
				//�������:001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
				print_now_time();
				cout<<"red "<<redw->name<<" "<<redw->serial<<" reached blue headquarter with "<<redw->health<<" elements and force "<<redw->force<<endl;
				HQ* temp=dynamic_cast<HQ*>(this);
				temp->is_captured=true;
			}
		}
		//�жϺ췽���� 
		if(HQ_flag==-1)
		{
			if(bluew!=NULL)
			{
				//�������:001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
				print_now_time();
				cout<<"blue "<<bluew->name<<" "<<bluew->serial<<" reached red headquarter with "<<bluew->health<<" elements and force "<<bluew->force<<endl;
				HQ* temp=dynamic_cast<HQ*>(this);
				temp->is_captured=true;
			}
		}
	}
	//�Լ����ǻ��� 
	else
	{
		print_now_time();
		cout<<(x->camp==red?"red ":"blue ")<<x->name<<" "<<x->serial<<" marched to city "<<city_serial<<" with "<<x->health<<" elements and force "<<x->force<<endl;
	}
	
	
}
//��ʿ�뿪 
void city::warrior_left(warrior* x)
{
	if(x->camp==red)
	{
		if(redw_Buff==NULL)
		{
			redw=NULL;
		}
		else
		{
			redw=redw_Buff;
			redw_Buff=NULL;
		}
	}
	else
	{
		if(bluew_Buff==NULL)
		{
			bluew=NULL;	
		}
		else
		{
			bluew=bluew_Buff;
			bluew_Buff=NULL;
		}
	}	
}
//����Ƿ���wolf��������
void city::check_rob()
{
	if(redw!=nullptr&&bluew!=nullptr)
	{
		if(redw->name=="wolf"&&bluew->name!="wolf")
		{
			wolf* rt=dynamic_cast<wolf*>(redw);
			rt->rob_weapon(bluew,this);
		}
		else if(redw->name!="wolf"&&bluew->name=="wolf")
		{
			wolf* bt=dynamic_cast<wolf*>(bluew);
			bt->rob_weapon(redw,this);
		}
	}
}
//����Ƿ��ܷ���ս�� 
void city::check_battle()
{
	if(redw&&bluew)   //����ս�� 
	{
		//��˫���������ź���
		sort(redw->weapons.begin(),redw->weapons.end(),weapons_resort);
		sort(bluew->weapons.begin(),bluew->weapons.end(),weapons_resort);
		vector<weapon*>::iterator x1=redw->weapons.begin();
		vector<weapon*>::iterator x2=bluew->weapons.begin();
		//���˫����Ѫ����ս���в��ٷ����仯����Ӧ��continue_battleΪfalse 
		bool health_changed=true;
		//���˫�������������꣬��Ӧ��any_weapon_leftΪfalse 
		bool any_weapon_left;
		if((x1!=redw->weapons.end())||(x2!=bluew->weapons.end()))
		{
			any_weapon_left=true;
		} 
		else
		{
			any_weapon_left=false;
		}  
		//�ж�����
		if(city_serial%2!=0)//�췽���� 
		{
			while(redw&&bluew&&health_changed&&any_weapon_left)
			{
				int rh1=(redw->health);
				int bh1=(bluew->health);
				int status1=0,status2=0;
				if(x1!=redw->weapons.end())
				{
					status1=(redw->attack(bluew,*x1));
					cout<<"���ԣ�bluew->health="<<bluew->health<<endl;
				}
				if(x2!=bluew->weapons.end())
				{
					status2=(bluew->attack(redw,*x2));
					cout<<"���ԣ�redw->health="<<redw->health<<endl;
				}
				if(status1)
				{
					//ɾ���������
					vector<weapon*>::iterator x1t=x1;
					x1=redw->weapons.erase(x1t); 
				}
				else if(x1!=redw->weapons.end())
				{
					++x1;
				}
				else if(x1==redw->weapons.end())    //һ����������
				{
					x1=redw->weapons.begin();	//x1����ָ��ͷ 	
				} 
				if(status2)
				{
					//ɾ��������� 
					vector<weapon*>::iterator x2t=x2;
					x2=bluew->weapons.erase(x2t);
				}
				else if(x2!=bluew->weapons.end())
				{
					++x2;
				}
				else if(x2==bluew->weapons.end())   //һ���������� 
				{
					x2=bluew->weapons.begin();      //x2����ָ��ͷ 
				}
				//���Ѫ���Ƿ����仯
				int rh2=(redw->health);
				int bh2=(bluew->health);
				if((rh1==rh2)&&(bh1==bh2))
				{
					health_changed==false;	
				}
				if(rh2<=0||bh2<=0)    //����Ƿ�������ȥ 
				{
					if(rh2<=0&&bh2<=0)    //ͬ���ھ� 
					{
						print_now_time();
						cout<<"both red "<<redw->name<<" "<<redw->serial<<" and blue "<<bluew->name<<" "<<bluew->serial<<" died in city "<<city_serial<<endl;
						redw->warrior_delete();
						bluew->warrior_delete();
						redw=nullptr; bluew=nullptr;		
					}
					else if(rh2>0&&bh2<=0)    //�췽ʤ�� 
					{ 
						//�췽�ɻ���������
						sort(bluew->weapons.begin(),bluew->weapons.end(),weapons_resort_for_rob);
						while((!redw->weapons_is_full())&&(bluew->weapons.size()!=0)) 
						{
							vector<weapon*>::iterator temp=bluew->weapons.begin();
							redw->weapons.push_back(*temp);
							bluew->weapons.erase(temp);
						}
						print_now_time();
						cout<<"red "<<redw->name<<" "<<redw->serial<<" killed blue "<<bluew->name<<" "<<bluew->serial<<" in city "<<city_serial<<" remaining "<<redw->health<<" elements"<<endl;
						bluew->warrior_delete();
						bluew=nullptr;
					}
					else if(rh2<=0&&bh2>0)    //����ʤ��
					{
						//�����ɻ�췽����
						sort(redw->weapons.begin(),redw->weapons.end(),weapons_resort_for_rob); 
						while((!bluew->weapons_is_full())&&(redw->weapons.size()!=0)) 
						{
							vector<weapon*>::iterator temp=redw->weapons.begin();
							bluew->weapons.push_back(*temp);
							redw->weapons.erase(temp);
						}
						print_now_time();
						cout<<"blue "<<bluew->name<<" "<<bluew->serial<<" killed red "<<redw->name<<" "<<redw->serial<<" in city "<<city_serial<<" remaining "<<bluew->health<<" elements"<<endl;
						redw->warrior_delete();
						redw=nullptr;	
					}	
				} 
				//����Ƿ���ʣ������ 
				if(redw&&bluew)
				{ 
					if((redw->weapons.begin()!=redw->weapons.end())||(bluew->weapons.begin()!=bluew->weapons.end()))
					{
						any_weapon_left=true;
					} 
					else
					{
						any_weapon_left=false;
					}
				}		
			}
		}
		else				//�������� 
		{
			while(redw&&bluew&&health_changed&&any_weapon_left)
			{
				int rh1=(redw->health);
				int bh1=(bluew->health);
				int status1=0,status2=0;
				if(x2!=bluew->weapons.end())
				{
					status2=(bluew->attack(redw,*x2));
					cout<<"���ԣ�redw->health="<<redw->health<<endl;
				}
				if(x1!=redw->weapons.end())
				{
					status1=(redw->attack(bluew,*x1));
					cout<<"���ԣ�bluew->health"<<bluew->health<<endl;
				}
				if(status1)
				{
					//ɾ���������
					vector<weapon*>::iterator x1t=x1;
					x1=redw->weapons.erase(x1t); 
				}
				else if(x1!=redw->weapons.end())
				{
					++x1;
				}
				else if(x1==redw->weapons.end())    //һ����������
				{
					x1=redw->weapons.begin();	//x1����ָ��ͷ 	
				} 
				if(status2)
				{
					//ɾ��������� 
					vector<weapon*>::iterator x2t=x2;
					x2=bluew->weapons.erase(x2t);
				}
				else if(x2!=bluew->weapons.end())
				{
					++x2;
				}
				else if(x2==bluew->weapons.end())   //һ���������� 
				{
					x2=bluew->weapons.begin();      //x2����ָ��ͷ 
				}
				//���Ѫ���Ƿ����仯
				int rh2=(redw->health);
				int bh2=(bluew->health);
				if((rh1==rh2)&&(bh1==bh2))
				{
					health_changed==false;	
				}
				if(rh2<=0||bh2<=0)    //����Ƿ�������ȥ 
				{
					if(rh2<=0&&bh2<=0)    //ͬ���ھ� 
					{
						print_now_time();
						cout<<"both red "<<redw->name<<" "<<redw->serial<<" and blue "<<bluew->name<<" "<<bluew->serial<<" died in city "<<city_serial<<endl;
						redw->warrior_delete();
						bluew->warrior_delete();
						redw=nullptr; bluew=nullptr;		
					}
					else if(rh2>0&&bh2<=0)    //�췽ʤ�� 
					{
						//�췽�ɻ���������
						sort(bluew->weapons.begin(),bluew->weapons.end(),weapons_resort_for_rob);
						while((!redw->weapons_is_full())&&(bluew->weapons.size()!=0)) 
						{
							vector<weapon*>::iterator temp=bluew->weapons.begin();
							redw->weapons.push_back(*temp);
							bluew->weapons.erase(temp);
						}
						print_now_time();
						cout<<"red "<<redw->name<<" "<<redw->serial<<" killed blue "<<bluew->name<<" "<<bluew->serial<<" in city "<<city_serial<<" remaining "<<redw->health<<" elements"<<endl;
						bluew->warrior_delete();
						bluew=nullptr;
					}
					else if(rh2<=0&&bh2>0)    //����ʤ��
					{
						//�����ɻ�췽����
						sort(redw->weapons.begin(),redw->weapons.end(),weapons_resort_for_rob); 
						while((!bluew->weapons_is_full())&&(redw->weapons.size()!=0)) 
						{
							vector<weapon*>::iterator temp=redw->weapons.begin();
							bluew->weapons.push_back(*temp);
							redw->weapons.erase(temp);
						}
						print_now_time();
						cout<<"blue "<<bluew->name<<" "<<bluew->serial<<" killed red "<<redw->name<<" "<<redw->serial<<" in city "<<city_serial<<" remaining "<<bluew->health<<" elements"<<endl;
						redw->warrior_delete();
						redw=nullptr;	
					}	
				} 
				//����Ƿ���ʣ������
				if(redw&&bluew)
				{ 
					if((redw->weapons.begin()!=redw->weapons.end())||(bluew->weapons.begin()!=bluew->weapons.end()))
					{
						any_weapon_left=true;
					} 
					else
					{
						any_weapon_left=false;
					}
				}
			}	
		}
		
		//������
		
		//���ȼ����������(ͬ���ھ���һ��ʤһ����)
		if(redw&&bluew)
		{
			//����������������
			print_now_time();
			cout<<"both red "<<redw->name<<" "<<redw->serial<<" and blue "<<bluew->name<<" "<<bluew->serial<<" were alive in city "<<city_serial<<endl;
		}
		 
	}
}
city::~city()
{
	
}
