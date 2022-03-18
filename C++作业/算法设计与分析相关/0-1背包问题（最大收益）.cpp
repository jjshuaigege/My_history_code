#include <iostream>
using namespace std;
/*
状态P[w][j]  w代表总重量，j挑选的物品数目（有顺序！按事先排好的顺序） 
递推关系  p[w][j]=max{p[w][j-1],p[w-wj][j-1]+p[j]}
边界      p[w][0]=0,p[0][j]=0
*/
int main()
{
	int W;      //总重量
	int n;      //物品数目 
	cout<<"输入总重量和数目:";
	cin>>W>>n;
	int w[n+1];    //每件物品的重量 
	int p[n+1];    //每件物品的价值 
	int P[W+1][2];      //状态空间(滚动数组，节省空间)
	cout<<"输入各重量:";
	for(int i=1;i<=n;++i)
	{
		cin>>w[i];
	} 
	cout<<"输入各价值:";
	for(int i=1;i<=n;++i)
	{
		cin>>p[i];
	}
	for(int i=0;i<W+1;i++)
	{
		P[i][0]=0;
	}
	P[0][1]=0;
	for(int j=1;j<=n;j++)   //循环n次
	{
		for(int i=1;i<=W;i++)       
		{
			if(i-w[j]>=0)
			{
				P[i][1]=max(P[i-w[j]][0]+p[j],P[i][0]);	
			}
			else
			{
				P[i][1]=P[i][0];
			}
		}
		//复原
		for(int i=1;i<=W;i++)
		{
			P[i][0]=P[i][1];
		} 
	}
	for(int i=0;i<=W;i++)
	{
		for(int j=0;j<=1;j++)
		{
			cout<<P[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

