#include <iostream>
//ŷ������㷨,���Լ�� 
using namespace std;
int maxcommon(int a,int b)
{
	int ret=a%b;
	while(ret!=0)
	{
		a=b;
		b=ret;
		ret=a%b;
	}
	return b;
}
int main()
{
	int x,y;
	while(cin>>x>>y)
	cout<<"���Լ��Ϊ��"<<maxcommon(x,y);
	return 0;
}

