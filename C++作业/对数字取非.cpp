#include <iostream>
using namespace std;
int main()
{
//	int* a=new int[100];
//	int a[100]={0};
//	a[0]=0;
//	a[1]=1;
//	printf("%d %d\n",a[0],a[1]);
//	printf("%d\n",sizeof(a));
	int x;
	scanf("%d",&x);
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	for(int k:a)
	{
		if(k==x)
		printf("ур╣╫ак");
	}
	return 0;
}

