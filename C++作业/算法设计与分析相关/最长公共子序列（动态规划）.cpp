#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//思路
//1.建立状态max_length[i][j](0<=i<a.size()&&0<=j<b.size()) ，它的意义是以a[i]结尾的a的连续子序列和以b[j]结尾的b的连续子序列的公共子序列的最大长度  
//2.边界 max_length[0][j]=0&&max_length[i][0]=0
//3.递推 
//(1)若a[i]=b[j]: max_length[i][j]=max_length[i-1][j-1]+1
//(2)否则 max_length[i][j]=max{max_length[i-1][j],max_length[i][j-1]}
int main()
{
	char buf;
	vector<char> a,b;
	while(cin>>buf)
	{
		a.push_back(buf);	
	}
	cin.clear();
	while(cin>>buf)
	{
		b.push_back(buf);
	}
	int max_length[a.size()][b.size()];
	for(int i=0;i<a.size();++i)
	{
		max_length[i][0]=0;
	}
	for(int j=0;j<b.size();++j)
	{
		max_length[0][j]=0;
	}
	for(int i=1;i<a.size();++i)
		for(int j=1;j<b.size();++j)
		{
			if(a[i]==b[j])
				max_length[i][j]=max_length[i-1][j-1]+1;
			else
				max_length[i][j]=max(max_length[i-1][j],max_length[i][j-1]);
		}
	cout<<max_length[a.size()-1][b.size()-1]<<endl;
	
	//求具体的序列
	int x=a.size()-1,y=b.size()-1;
	int c=max_length[x][y];
	vector<char> object;
	while(c!=0)
	{
		if(c==max_length[x][y-1])
		{
			y=y-1;	
		}
		else if(c==max_length[x-1][y])
		{
			x=x-1;	
		}
		else
		{
			object.push_back(a[x]);
			x=x-1;
			y=y-1;
		}
		c=max_length[x][y];	
	}
	reverse(object.begin(),object.end());
	for(int i=0;i<object.size();++i)
	{ 
		cout<<object[i]<<" ";
	} 
	 cout<<endl;
	return 0;
}

