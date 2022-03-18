#include <iostream>
using namespace std;
inline int add(int a,int b)
{
	cout<<"这是一个内联函数"<<endl;
	return (a+b);
}
int main()
{
	int a=22;
	int b=44;
	int c=add(a,b);
	cout<<c<<endl;
	return 0;
}

