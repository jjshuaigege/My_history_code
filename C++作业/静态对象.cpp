#include <iostream>
using namespace std;
class A
{
	int cnt;
	public:
		A():cnt(0){cout<<"����A�Ĺ��캯��"<<endl;}
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
	cout<<"�����뿪main����"<<endl;
	return 0;
}

