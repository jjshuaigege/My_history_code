#include <iostream>
using namespace std;
class B
{
	public:
		void print()
		{
			cout<<"hello"<<endl;
		}
		int Bvalue;
		B():Bvalue(56)
		{
			
		}
};
class A
{
	public:
		int value=32;
		B b;
//		A():value(64)
//		{
//			value=128;
//		}
};
int main()
{
	A a;
	cout<<a.value<<endl;
	a.b.print();
	cout<<a.b.Bvalue<<endl;
	return 0;
}

