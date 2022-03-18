#include <iostream>
using namespace std;
class A
{
	private:
		int a;
		double b;
	public:
		A(int a,double b):a(a),b(b)
		{
			
		}
		virtual ~A()
		{
			cout<<"~A()"<<endl;
		}
};
class B:public A
{
	public:
		B(int a,double b):A(a,b)
		{
			
		}
		~B()
		{
			cout<<"~B()"<<endl;
		}
};
int main()
{
	A* p=new B(3,2.2);
	delete p;
	return 0;
}

