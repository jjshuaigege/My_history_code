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
	//����ͳ�ʼ��һ������ָ�� 
	int (* funcp)(const char*)=func;
	cout<<(funcp)(a)<<":";
	return 0;
}

