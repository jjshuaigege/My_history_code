#include <stdio.h>
int main()
{
	int a,b;
	int big,small;
	int rem=-1;
	scanf("%d %d",&a,&b);
	if(a<=0||b<=0)
	return 1;
	else if(a>b)
	{
		big=a;
		small=b;
	}
	else
	{
		big=b;
		small=a;
	}
	while(rem!=0)
	{
		rem=big%small;
		big=small;
		small=rem;
	}
	//循环结束，big为最大公约数
	long c,d;
	c=big;
	d=a*b/c; 
	printf("%d %d",c,d);
    return 0;
}

