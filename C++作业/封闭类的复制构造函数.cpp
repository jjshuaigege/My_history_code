#include <iostream>
using namespace std;
class A
{
	public:
		A()
		{
			cout<<"A constructor called"<<endl;
		}
		A(A& a)
		{
			cout<<"A copy called"<<endl;
		}
};
class B
{
	private:
		A a;
};
int main()
{
	B b1,b2(b1);
	return 0;
}

