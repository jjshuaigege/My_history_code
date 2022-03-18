#include <iostream>
//欧几里得算法,最大公约数 
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
	cout<<"最大公约数为："<<maxcommon(x,y);
	return 0;
}

