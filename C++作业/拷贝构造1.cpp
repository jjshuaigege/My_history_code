#include <iostream>
using namespace std;
class A
{
	public:
	A():i(20){cout<<"A�Ĺ��캯��"<<endl;}
	A(const A& a):i(20){cout<<"A�Ĺ��캯��"<<endl;}      //A�г���Ա������Ŀ������캯�� 
	int i;
};
class B                                           //B�Ŀ������캯���Ǳ��������� 
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

