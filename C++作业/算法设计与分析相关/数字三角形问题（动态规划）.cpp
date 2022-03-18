#include <iostream>
using namespace std;
//�����ʽ��
//��һ�е�n�����ж����� n������100 
//����n������������������ÿ���������ֵ
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
			max_doc[i][j]=-1;     //Ϊ-1��ʾ��δ�м�¼ 
			cin>>num[i][j];
		}
	cout<<max_path(0,0)<<endl;
	return 0;
}

