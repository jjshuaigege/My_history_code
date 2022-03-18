#include <iostream>
using namespace std;
class A
{
	public:
		int i;
		A():i(30){}
};
A f()
{
	A a;
	return a;
}
int main()
{	
	f().i=40;
	return 0;
}

