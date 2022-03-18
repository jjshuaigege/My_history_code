#include <stdio.h>
#include <stdlib.h> 
int main()
{
	while(1)
	{
	int num; 
	scanf("%d",&num);
	int *a;
	a=(int*)malloc(sizeof(int)*num);
	for(int i=0;i<num;i++)
	{
		a[i]=i;
	}
	for(int i=num-1;i>=0;i--)
	{
		printf("%d",a[i]);
		if(i>0)
		printf(" ");
	}
	printf("\n");
	}
    return 0;
}

