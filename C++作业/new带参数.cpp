#include <iostream>
using namespace std;
class A
{
	int a;
	public:
	A(int a):a(a)
	{
		
	}
};
int main()
{
	A* p=new A[5](12);
	return 0;
}

