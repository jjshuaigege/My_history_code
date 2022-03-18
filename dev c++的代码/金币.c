#include <stdio.h>
int receive_gold(int n);
int main()
{
	int k;
	scanf("%d",&k);
	int a=receive_gold(k);
	printf("%d",a);
    return 0;
}
int receive_gold(int n)
{
	int sum=0;
	int i;
	for(i=1;sum<n;i++)
	{
		sum+=i;
	}
	i--;   //此时i=sum（天数）的一天的金币 
	int outcome;
	int sum1=0;
	for(int j=1;j<i;j++)
	{
		int chengji=1;
		
		for(int k=0;k<2;k++)
		{
			chengji*=j;
		}
		sum1+=chengji;   //1+2+2;
	}
	int sum0=0;
	for(int l=1;l<i;l++)
	{
		sum0+=l;       //1+2=3
	}
	outcome=(n-sum0)*i+sum1;                 //n=5,n-sum0=2
	return outcome;
}
/*n=6
1.sum=1,i=2  //sum代表天数 
2.sum=3,i=3
3.sum=6,i=4
第4，5，6天收到3枚金币
第7，8，9，10天收到4枚举金币*/ 

