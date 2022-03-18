#include <iostream>
/*
题目描述
求长为w，宽为h的蛋糕，切m刀所得到的最大块，在所有情况中的最小值 
（注意，每刀只单独切一块完整的蛋糕） 
状态:ways(wi,hj,mk)
边界：
（1）当wihj<mk+1时 ways=无穷大 
（2）当mk==0,ways=wihi
递推：
ways(w,h,m)=min{SV,SH}竖着/横着切一刀
SV=min{Si,i=1,2,3,...,h-1}  i代表切口左边的蛋糕的长度 
Si=min{max{ways(i,h,k},ways(w-i,h,m-1-k) k=0,1,2,...,m-1}
 
*/ 
using namespace std;
int main()
{
	int W,H,M;   //长为W宽为H的蛋糕切M刀
	
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
					//边界 
					if(m==0)
					{
						ways[w][h][m]=w*h;
					}
					else if(w*h<m+1)
					{
						ways[w][h][m]=W*H;
					}
					//递推 
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
	
	
	//递推
	 
	 
	return 0;
}

