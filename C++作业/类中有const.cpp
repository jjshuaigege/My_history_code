#include <iostream>
using namespace std;
class A
{
	public:
	const int a;
	A():a(50) 
	{
	}
};
int main()
{
	A j;
	cout<<j.a<<endl;
	return 0;
}

