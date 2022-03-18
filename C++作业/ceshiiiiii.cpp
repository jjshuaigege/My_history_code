#include <iostream>
using namespace std;
class A
{
	public:
	int a;
	double b=3.2;
		A(int x):a(x)
		{
			
		}
};
int main()
{
	A a=2;
	a=3;
	cout<<a.a<<","<<a.b<<endl;
	return 0;
}

