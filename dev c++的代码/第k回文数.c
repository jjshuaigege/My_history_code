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
		int mask=1,weishu=0;
		int temp=num;
		while(temp!=0)
		{
			temp=temp/10;
			weishu++;
		}
		for(int i=0;i<weishu-1;i++)
		{
			mask*=10;
		}
		temp=num;
		int a=0,b;
		while(temp!=0)
		{
		a+=temp%10*mask;
		temp/=10;
		mask/=10;
		}
		if(a==num)
		cnt++;
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

