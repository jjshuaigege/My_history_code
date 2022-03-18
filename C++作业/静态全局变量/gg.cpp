#include <stdio.h>
void func(int n);
int main()
{
	int a;
	scanf("%d",&a);
	func(a);
}
void func(int n)
{
	if(n>0)
	{
		printf("%d",n%10);
		func(n/10);
	}
	else return;
}

