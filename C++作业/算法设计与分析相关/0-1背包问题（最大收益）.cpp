#include <iostream>
using namespace std;
/*
״̬P[w][j]  w������������j��ѡ����Ʒ��Ŀ����˳�򣡰������źõ�˳�� 
���ƹ�ϵ  p[w][j]=max{p[w][j-1],p[w-wj][j-1]+p[j]}
�߽�      p[w][0]=0,p[0][j]=0
*/
int main()
{
	int W;      //������
	int n;      //��Ʒ��Ŀ 
	cout<<"��������������Ŀ:";
	cin>>W>>n;
	int w[n+1];    //ÿ����Ʒ������ 
	int p[n+1];    //ÿ����Ʒ�ļ�ֵ 
	int P[W+1][2];      //״̬�ռ�(�������飬��ʡ�ռ�)
	cout<<"���������:";
	for(int i=1;i<=n;++i)
	{
		cin>>w[i];
	} 
	cout<<"�������ֵ:";
	for(int i=1;i<=n;++i)
	{
		cin>>p[i];
	}
	for(int i=0;i<W+1;i++)
	{
		P[i][0]=0;
	}
	P[0][1]=0;
	for(int j=1;j<=n;j++)   //ѭ��n��
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
		//��ԭ
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

