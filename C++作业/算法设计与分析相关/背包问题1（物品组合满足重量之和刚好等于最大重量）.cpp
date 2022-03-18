#include <iostream>
using namespace std;
int main()
{
	int W;  //背包总重量 
	int k;  //物品总数目 
	cin>>W>>k;
	int w[k+1];   //记录各个物品重量
	int ways[W+1][k+1];
	for(int i=1;i<k+1;++i)
	{
		cin>>w[i];	
	} 
	for(int j=0;j<k+1;++j)
	{
		ways[0][j]=1;
	}
	for(int i=1;i<W+1;++i)
	{
		ways[i][0]=0;
	}
	for(int i=1;i<W+1;++i)
	{
		for(int j=1;j<k+1;++j)
		{
			ways[i][j]=ways[i][j-1];
			if(i-w[j]>=0)
			{
				ways[i][j]=ways[i][j]+ways[(i-w[j])][j-1];
			}
		}
	}
	cout<<ways[W][k]<<endl;
	cout<<endl;
	//打印查看结果 
	for(int i=0;i<W+1;++i)
	{
		for(int j=0;j<k+1;++j)
		{
			cout<<ways[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

