#include <stdio.h>
int findhuiwen(int);
int main()
{
	int n,outcome;
	scanf("%d",&n);
	int a[n];//用来装放回文数的次序 
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		outcome=findhuiwen(a[i]);
		printf("%d\n",outcome);
	}
    return 0;
}
int findhuiwen(int pos)
{
	int	cnt=0,num=1;
	for(num=1;cnt<pos;num++)
	{
		int temp=num;
		int a=0;
		while(temp!=0)
		{
			a=a*10+temp%10;
			temp/=10;
		}
		if(a==num)
		cnt++;
		//num=12
		// 1.a=2,temp=1
		// 2.a=21,temp=0
		// num=125
		// 1.a=5,temp=12
		// 2.a=52,temp=1
		// 3.a=521,temp=0 
		/*while(temp!=0)
		{
			temp=temp/10;
			weishu++
		}
		for(int i=0;i<weishu-1;i++)
		{
			mask*=10
		}
		*/
	}
	return num-1;
}
