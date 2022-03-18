#include <iostream>
#include <string>
using namespace std;
class A
{
	public:
		virtual string info(int x)
		{
			string s="123";
			return s;
		}
};
class B:public A
{
	public:
		virtual string info(double x)
		{
			string s="456";
			return s;
		}
};
class C:public B
{
	public:
		virtual string info(int x)
		{
			string s="789";
			return s;
		}
};
int main()
{
	B b;
	C c;
	A& a_b=b;
	A& a_c=c;
	cout<<a_b.info(1.2)<<endl;
	cout<<a_c.info(1.2)<<endl;
	return 0;
}

