#include <iostream>
using namespace std;
class A
{
	public:
	A():i(20){cout<<"A的构造函数"<<endl;}
	A(const A& a):i(20){cout<<"A的构造函数"<<endl;}      //A有程序员所定义的拷贝构造函数 
	int i;
};
class B                                           //B的拷贝构造函数是编译器给的 
{
	public:
	B(float x,double y):b(x),c(y){}
	A a;
	float b;
	double c;
};
int main()
{
//	A a(10,60);
//	cout<<a.i<<endl<<a.j<<endl<<a.k<<endl;
	B b1(2.6,3.14159);
	B b2=b1;
}

