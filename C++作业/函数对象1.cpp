#include <iostream>
using namespace std;
class A
{
	private:
		int a;
		int b;
	public:
		operator()(int a,int b)
		{
			cout<<"operator()(int a,int b)"<<endl;
			cout<<a<<","<<b<<endl;
		}
		void print()
		{
			cout<<"Hello"<<endl;
		}
};
int main()
{
	A a;
	a(6,38);
	return 0;
}

