#include <iostream>
using namespace std;
class A
{
	private:
		int value=55;
	public:
		virtual int get();
		
};
int A::get()
	{
		cout<<"in A"<<endl; 
		return value;
	}
class B:public A
{
	public:
		int value=66;
	public:
		get()
		{
			cout<<"in B"<<endl; 
			return value;
		}
};
class C:public B
{
	private:
		int value=77;
	public:
		get()
		{
			cout<<"in C"<<endl; 
			return 1.2*value;
		}
};
int main()
{
	B b;
	C c;
	//ͨ��ָ��ʵ�ֶ�̬ 
	A* p=NULL;
	p=&b;
	cout<<p->get()<<endl;
	A* p1=&c;
	cout<<p1->get()<<endl;
	//ͨ������ʵ�ֶ�̬
	A& a=c;
	cout<<a.get()<<endl; 
	//��������
	A* p2=&b;
	cout<<p2->value<<endl;
	//��������
	B* p3=(B*)p2 
	
	return 0;
}

