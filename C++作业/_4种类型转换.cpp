#include <iostream>
using namespace std;
class A
{
	public:
	int i;
	int j;
	A(int n):i(n),j(n)
	{
		
	}
	void virtual print()
	{
		cout<<i<<" "<<j<<" "<<endl;
	}
};
class B:public A
{
	public:
		int k;
		B(int n):A(n),k(n)
		{
			
		}
		void print()
		{
			cout<<i<<" "<<j<<" "<<k<<endl;
		}
};
int main()
{
	int *p;
	int a=10;
	double b=9.6;
	
	//��һ��static_cast<>(),���ڷ��յ͵�����ת��,���������ͣ������븡�� 
	cout<<static_cast<int>(b)<<endl; 
	//�ڶ���reinterpret_cast<>() ������ָ��֮�䣬ָ�������֮�� 
	p=reinterpret_cast<int*>(a);
	cout<<p<<endl;
	//����һ������
	A a1(120);
	int& r=reinterpret_cast<int&>(a1);
	r=200;
	/*����Ĵ����Ч��
	int *p=reinterpret_cast<int*>(&a1);
	*p=200;
	 */
	cout<<a1.i<<" "<<a1.j<<endl;
	//������const_cast<>() ��const����ת��Ϊ��const 
	const A a2(210);
	A& j1=const_cast<A&>(a2);
	j1.i=220;j1.j=230;
	cout<<j1.i<<" "<<j1.j<<endl;
	//������dynamic_cast<>()   ������ָ��ת��Ϊ������ָ��(�����Ƕ�̬�ģ� 
	A a4(320);
	A* l1=&a4;
	B* l2=dynamic_cast<B*>(l1);
	if(l2==NULL)
	{
		cout<<"error"<<endl;
	}
	else
	{
		cout<<l3->k<<endl;
	}
//	l2->print1();

}

