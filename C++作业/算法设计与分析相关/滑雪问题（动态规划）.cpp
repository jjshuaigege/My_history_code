#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
//��ѩ
/*
�������� 
1	2	3	4	5
16	17	18	19	6
15	24	25	20	7
14	23	22	21	8
13	12	11	10	9
�������
25
(���ͣ�(25->24->23->22->21->...->1)) 
˼· 
״̬���Ե�iΪ��㣬����Ӧ�����ѩ����Li 
�߽磺ÿһ���������������ĵ㣺��Χ��ĸ߶Ⱦ����ڻ�����Լ�
����:����i��Ӧ����һ���ǿռ���X��X���������j���ڼ���X����j��i���ڽӵ㣬��hj<hi,��ôli=max{lj} (����j����X��
���Ƶķ����Ż����Ƚ������㰴�߶����򣬴�С�������������i������Χ�ĵ�k�������i��������Χ�����k��lȡmax(lk,li+1) 
*/
bool height_sort(tuple<int,int,int> a,tuple<int,int,int> b)
{
	return (get<2>(a))<(get<2>(b));
}
int main()
{
	int r,c; //r,c����ѩ���ص����������� 
	int buf; //�������� 
	cin>>r>>c;
	int l[r][c];
	int h[r][c];
	vector<tuple<int,int,int> > xy_h;   //���߶�����
	//���������ĸ߶ȣ���֮����һ����λ��
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
			if(dx[k]+ox<c&&dx[k]+ox>=0&&dy[k]+oy<r&&dy[k]+oy>=0)  //��Խ�߽� 
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
	cout<<"��ѩ�������Ϊ"<<ret<<endl;
	return 0;
}

