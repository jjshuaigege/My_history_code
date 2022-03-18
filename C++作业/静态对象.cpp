#include <iostream>
using namespace std;
class A
{
	int cnt;
	public:
		A():cnt(0){cout<<"调用A的构造函数"<<endl;}
		~A(){cout<<"A::~A()"<<endl;}
};
void f()
{
	cout<<"begin of f"<<endl;
	static A a;
	cout<<"end of f"<<endl;	
}
int main()
{
	for(int i=0;i<10;i++)
	{
		f();
	}
	cout<<"即将离开main函数"<<endl;
	return 0;
}

