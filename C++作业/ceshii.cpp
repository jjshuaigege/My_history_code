#include <iostream>
using namespace std;
int main()
{
	int x;
	scanf("%d",&x);
	const int size=x;
	int a[size];
//	int a[size]={0,1,2,3,4,5,6,7,8,9};
	for(int i=0;i<size;i++)
	{
		a[i]=i;
	}
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}

