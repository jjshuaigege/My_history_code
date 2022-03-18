#include <iostream>
#include <tuple>
using namespace std;
class A
{
	int a;
	
	public:
		A()
		{
			cout<<"A() was called"<<endl;
		}
		A(const A& x)
		{
			cout<<"A(const A& x)"<<endl;
		}
};
int main()
{
	pair<int,int> a(pair<double,double>(5.5,6.6));
	cout<<"("<<a.first<<","<<a.second<<")"<<endl;
	return 0;
}

