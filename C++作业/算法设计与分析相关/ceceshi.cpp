#include <iostream>
using namespace std;
class A
{
	private:
		int a;
		double b;
	public:
		A()
		{
			cout<<"A()"<<endl;	
		}
		A(int x):a(x)
		{
			cout<<"A(int x):a(x)"<<endl;	
		} 
		void print()
		{
			cout<<"a="<<a<<","<<"b="<<b<<endl;	
		}
};
int main()
{
	A* p=new A();
	p->print();
	A a(1);
	a.print();
	return 0;
}

