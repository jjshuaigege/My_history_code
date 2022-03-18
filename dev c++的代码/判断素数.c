#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
	while(1)
	{
	int n;
	int isprime;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d ",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
	isprime=judgeprime(a[i]);
	if(isprime==1)
	printf("1");
	else
	printf("0");
	if(i<n)
	printf(" ");
	}
	printf("\n");
	return 0;
}
int judgeprime(int n)
{
	int isprime=1;
	if(n==1||(n%2==0&&n!=2))
	isprime=0;
	else for(int i=3;i<=sqrt(n);i+=2)
	{
		if(n%i==0)
		isprime=0;
	}
	return isprime;	
} 

