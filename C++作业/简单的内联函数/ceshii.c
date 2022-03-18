#include <stdio.h>
int main()
{
	const int size=10;
//	int size;
//	scanf("%d",&size);
	int a[size];
	for(int i=0;i<size;i++)
	{
		a[i]=i;
	}
	for(int i=0;i<size;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}

