#include <iostream>
using namespace std;
class A
{
	public:
		A();
		~A();
		void f(int i);
	private:
		int i;
};
void A::f(int i)
{
	this->i=i;
}
A::A()
		{
			i=0;
			cout<<"i="<<i<<endl;
		}
A::~A()
		{
			cout<<"A::~A()"<<endl;
			cout<<"i="<<i<<endl;
		}
int main()
{
	A* p=new A[10];
	for(int j=0;j<10;j++)
	{
		p[j].f(j);
	}
	A a;
	a.A::A();
	delete p;                     //delete不加[]，只调用一次析构函数 
	return 0;
}

