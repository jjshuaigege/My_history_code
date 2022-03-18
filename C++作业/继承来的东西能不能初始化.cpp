#include <iostream>
using namespace std;
class A
{
	protected:
	int a;
	public:
		A()
		{
//			show();
		}
		virtual void show()
		{
			cout<<"A::show()"<<endl;
		}
		void ps()
		{
			show();
		}
};
class B:public A
{
	public:
	B()
	{
//		show();
	}
	void print_show()
	{
		show();
	}
	virtual void show()
	{
		cout<<"B::show()"<<endl;
	}
};

int main()
{
	A* a=new B;
	a->ps();
}

