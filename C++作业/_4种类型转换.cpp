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
	
	//第一种static_cast<>(),用于风险低的类型转换,整型与整型，浮点与浮点 
	cout<<static_cast<int>(b)<<endl; 
	//第二种reinterpret_cast<>() ，用于指针之间，指针与变量之间 
	p=reinterpret_cast<int*>(a);
	cout<<p<<endl;
	//来看一个特例
	A a1(120);
	int& r=reinterpret_cast<int&>(a1);
	r=200;
	/*上面的代码等效于
	int *p=reinterpret_cast<int*>(&a1);
	*p=200;
	 */
	cout<<a1.i<<" "<<a1.j<<endl;
	//第三种const_cast<>() 将const变量转换为非const 
	const A a2(210);
	A& j1=const_cast<A&>(a2);
	j1.i=220;j1.j=230;
	cout<<j1.i<<" "<<j1.j<<endl;
	//第四种dynamic_cast<>()   将基类指针转化为派生类指针(必须是多态的） 
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

