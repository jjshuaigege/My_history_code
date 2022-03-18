#include <iostream>
#include <map>
using namespace std;
class A
{
	int a;
	double b;
	public:
		A()
		{
			a=10;
			b=9.8;
		}
		void print()
		{
			cout<<a<<" "<<b<<endl;
		}
};
int main()
{
	map<int,A> h;
	h[1]=A();
	h[1].print();
	
	return 0;
}

