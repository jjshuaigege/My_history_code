#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
//滑雪
/*
样例输入 
1	2	3	4	5
16	17	18	19	6
15	24	25	20	7
14	23	22	21	8
13	12	11	10	9
样例输出
25
(解释：(25->24->23->22->21->...->1)) 
思路 
状态：以点i为起点，所对应的最长滑雪长度Li 
边界：每一个满足这样条件的点：周围点的高度均高于或等于自己
递推:若点i对应这样一个非空集合X，X满足对任意j属于集合X，有j是i的邻接点，且hj<hi,那么li=max{lj} (其中j属于X）
递推的方法优化：先将各个点按高度排序，从小到大遍历各个点i，若周围的点k比这个点i大，则让周围这个点k的l取max(lk,li+1) 
*/
bool height_sort(tuple<int,int,int> a,tuple<int,int,int> b)
{
	return (get<2>(a))<(get<2>(b));
}
int main()
{
	int r,c; //r,c代表滑雪场地的行数和列数 
	int buf; //接收输入 
	cin>>r>>c;
	int l[r][c];
	int h[r][c];
	vector<tuple<int,int,int> > xy_h;   //按高度排序
	//输入各个点的高度（点之间间隔一个单位）
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			cin>>buf;
			h[i][j]=buf;
			xy_h.push_back(make_tuple(i,j,buf));
			l[i][j]=1;	
		}	
	}
	sort(xy_h.begin(),xy_h.end(),height_sort);
	
	const int dx[4]={-1,0,1,0};
	const int dy[4]={0,1,0,-1};
	for(auto i=xy_h.begin();i!=xy_h.end();++i)
	{
		int ox=get<0>(*i);
		int oy=get<1>(*i);
		for(int k=0;k<4;++k)
		{
			if(dx[k]+ox<c&&dx[k]+ox>=0&&dy[k]+oy<r&&dy[k]+oy>=0)  //不越边界 
			{
				if(h[dx[k]+ox][dy[k]+oy]>h[ox][oy])
				l[dx[k]+ox][dy[k]+oy]=l[dx[k]+ox][dy[k]+oy]>=l[ox][oy]+1?l[dx[k]+ox][dy[k]+oy]:l[ox][oy]+1;
			}
		}
	}
	int ret=l[0][0];
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			cout<<l[i][j]<<"\t";
			if(l[i][j]>ret)
			{
				ret=l[i][j];
			}	
		}
		cout<<endl;	
	}
	cout<<"滑雪的最长长度为"<<ret<<endl;
	return 0;
}

