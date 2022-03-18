#include <iostream>
using namespace std;
class A
{
	int a;
	double b;
	public:
		A()
		{
			cout<<"A() called"<<endl;
		}
		~A()
		{
			cout<<"~A() called"<<endl;
		}
}; 
class B:public A
{
	public:
		virtual ~B()
		{
			cout<<"~B() called"<<endl;
		}
}; 
int main()
{
	B b;
	return 0;
}

