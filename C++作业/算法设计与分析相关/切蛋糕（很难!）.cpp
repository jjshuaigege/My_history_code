#include <iostream>
/*
��Ŀ����
��Ϊw����Ϊh�ĵ��⣬��m�����õ������飬����������е���Сֵ 
��ע�⣬ÿ��ֻ������һ�������ĵ��⣩ 
״̬:ways(wi,hj,mk)
�߽磺
��1����wihj<mk+1ʱ ways=����� 
��2����mk==0,ways=wihi
���ƣ�
ways(w,h,m)=min{SV,SH}����/������һ��
SV=min{Si,i=1,2,3,...,h-1}  i�����п���ߵĵ���ĳ��� 
Si=min{max{ways(i,h,k},ways(w-i,h,m-1-k) k=0,1,2,...,m-1}
 
*/ 
using namespace std;
int main()
{
	int W,H,M;   //��ΪW��ΪH�ĵ�����M��
	
	cin>>W>>H>>M;
	M--;
	while(W!=0&&H!=0&&M!=0)
	{
		int ways[W+1][H+1][M+1];
		for(int w=1;w<W+1;++w)
		{
//			cout<<"w="<<w<<":"<<endl;
			for(int h=1;h<H+1;++h)
			{
				for(int m=0;m<M+1;++m)
				{
					//�߽� 
					if(m==0)
					{
						ways[w][h][m]=w*h;
					}
					else if(w*h<m+1)
					{
						ways[w][h][m]=W*H;
					}
					//���� 
					else
					{
						int SV=W*H,SH=W*H;
						for(int i=1;i<=H-1;i++)
						{
							int Si=W*H;
							for(int k=0;k<=m-1;++k)
							{
								int max_w;
								max_w=max(ways[i][h][k],ways[w-i][h][m-1-k]);
								if(Si>max_w)
								{
									Si=max_w;
								}
							}
							if(SV>Si)
							{
								SV=Si;
							}
						}
						for(int j=1;j<=W-1;j++)
						{
							int Sj=W*H;
							for(int k=0;k<=m-1;++k)
							{
								int max_w;
								max_w=max(ways[w][j][k],ways[w][h-j][m-1-k]);
								if(Sj>max_w)
								{
									Sj=max_w;
								}
							}
							if(SH>Sj)
							{
								SH=Sj;
							}	
						}
						ways[w][h][m]=min(SV,SH);
					}
//					cout<<ways[w][h][m]<<"\t";
				}
//				cout<<endl;
			}
//			cout<<endl<<endl<<endl;
		}
		cout<<ways[W][H][M]<<endl;
		cin>>W>>H>>M;
		M--;	
	}
	
	
	//����
	 
	 
	return 0;
}

