#include <iostream>
using namespace std;
class A
{
	int a;
	double b;
	public:
	A():a(10),b(8.8)
	{
		cout<<"A()"<<endl;
	}
};
int main()
{
	A a;
	return 0;
}

