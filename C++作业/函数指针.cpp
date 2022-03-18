#include <iostream>
using namespace std;
int func(const char* Buf)
{
	int n=88;
	cout<<Buf<<endl;
	return n;
}
int main()
{
	const char* a="Hello world";
	//定义和初始化一个函数指针 
	int (* funcp)(const char*)=func;
	cout<<(funcp)(a)<<":";
	return 0;
}

