#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
//int func1()
//{
//	int y=x;
//	return y;
//}
int main()
{
	int x=123456789;
	cout.width(7);
	cout<<x<<endl;
//	cout.precision(6);   //����"������"���� 
	cout.fill('!');
	cout.setf(ios::left);
	cout.width(7);
	cout<<12345<<"here"<<endl;
	cout.width(7);       //width()�Ƚ����⣬��һ���Ե� 
	cout<<x<<"here"<<endl;
//	cout.precision(5);   //����"������"���� 
//	cout<<x<<endl;
//	cout<<x<<endl;
	const int* p1=&x;
	int const* p2=&x;
	int* const p3=&x;
	*p3=999;
	printf("%d",x);
	
	return 0;
}

