#include <iostream>
using namespace std;
//输入格式：
//第一行的n代表有多少行 n不超过100 
//后续n行依次输入三角形中每个数具体的值
/*
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/ 
#define MAXSIZE 101

int max_doc[MAXSIZE][MAXSIZE];
int n;
int num[MAXSIZE][MAXSIZE];

int max_path(int row,int col)
{
	if(max_doc[row][col]!=-1)
	{
		return max_doc[row][col];
	}
	else
	{
		if(row==n-1)
		{
			max_doc[row][col]=num[row][col];
		}
		else
		{
			int x=max_path(row+1,col);
			int y=max_path(row+1,col+1);
			max_doc[row][col]=(x>=y?x:y)+num[row][col];
		}
		return max_doc[row][col];
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<=i;++j)
		{
			max_doc[i][j]=-1;     //为-1表示还未有记录 
			cin>>num[i][j];
		}
	cout<<max_path(0,0)<<endl;
	return 0;
}

