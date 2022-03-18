#include <iostream>
using namespace std;
class A
{
	public:
	int data;
	double b;
	A(int h):data(h),b(data)
	{
		
	}
	
};


int main()
{
	A a1(5);
	cout<<a1.b<<" "<<a1.data<<endl;
	return 0;
}

