#include <iostream>
using namespace std;
class A
{
	private:
		int valueA;
	public:
		A(int valueA=55):valueA(valueA)
		{
			
		}
		void print_A()
		{
			cout<<"valueA="<<valueA<<endl;
		}
};
class B
{
	private:
		int valueB;
	public:
		B(int valueB=66):valueB(valueB)
		{
			
		}
		void print_B()
		{
			cout<<"valueB="<<valueB<<endl;
		} 	
};
class C:public A,public B
{
	public:
		C(int valueA,int valueB):A(valueA),B(valueB)
		{
			
		}
};
int main()
{
	C c(70,80);
	c.print_A();
	c.print_B();
	cerr<<"Hello"<<endl;
	clog<<"Hello again"<<endl;
	return 0;
}

