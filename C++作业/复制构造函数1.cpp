#include <iostream>
using namespace std;
class A
{
	int a;
	double b;
	public:
	A(int a,double b):a(a),b(b)
	{
		
	}
	A(A& x)
	{
		cout<<"copy called"<<endl;
	}
};
int main()
{
	A a1(10,3.6);
	A a2=a1;
	return 0;
}

