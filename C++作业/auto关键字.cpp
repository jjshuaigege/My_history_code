#include <iostream>
#include <typeinfo>
using namespace std;
class A
{
	int a;
	double b;
	public:
	A(int a,double):a(a),b(b)
	{
		
	}
};
int main()
{
	auto a="Hello";
	auto b=21LL;
	auto c=36531.23;
	auto d=A{10,3.14};
	cout<<typeid(a).name()<<endl;
	cout<<typeid(b).name()<<endl;
	cout<<typeid(c).name()<<endl;
	cout<<typeid(d).name()<<endl;
	return 0;
}

