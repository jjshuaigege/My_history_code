#include <iostream>
using namespace std;
int func(double x)
{
	return x/2;
}
int func0(double x)
{
	return x/3;
}
int main()
{
	//����һ�����͵ĺ���ָ�� 
	typedef int (*F)(double);
	F f1=func;
	F f2=func0;
	cout<<f1(22.2)<<endl;
	cout<<f2(22.2)<<endl;
	return 0;
}

