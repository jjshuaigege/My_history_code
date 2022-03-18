#include <iostream>
using namespace std;
class A
{
	int a;
	public :
		A()
		{
			cout<<"A::A()"<<endl;		
		}
		A(int a):a(a)
		{
			cout<<"A::A(int a):a(a)"<<endl;
		}
		void print()
		{
			cout<<"a="<<a<<endl;
		}
};
class B
{
	private:
	A x;
	double b;
	public:
	B():x(),b()
	{
		cout<<"B::B():x(),b()"<<endl;
	}
	B(int a):x(a),b()
	{
		cout<<"B::B(int a):x(a),b()"<<endl;
	}
	B(int a,double b):x(a),b(b)
	{
		cout<<"B::B(int a,double b):x(a):b(b)"<<endl;
	}
	void print()
	{
		x.print();
		cout<<"b="<<b<<endl;
	}
};
int main()
{
	B b0(10,2.99);
	B b1(20);
	B b2;
	b0.print();
	b1.print();
	b2.print();
	return 0;
}

