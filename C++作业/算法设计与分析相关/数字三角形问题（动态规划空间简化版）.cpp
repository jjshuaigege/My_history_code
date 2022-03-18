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
#define MAXSIZE 100
int main()
{
	int n;
	int num[MAXSIZE][MAXSIZE];
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<=i;++j)
		{
			cin>>num[i][j];
		}
	for(int i=n-2;i>=0;--i)
		for(int j=0;j<=i;++j)
		{
			num[n-1][j]=(num[n-1][j]>=num[n-1][j+1]?num[n-1][j]:num[n-1][j+1])+num[i][j];
		}
		cout<<num[n-1][0]<<endl;
	return 0;
}

