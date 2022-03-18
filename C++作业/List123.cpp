#include <iostream>
#include <list>
#include <map>
using namespace std;
int main()
{
	map<int,list<int>> mh;
	int n;
	string cmd;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>cmd;
		int n1,n2;
		if(cmd=="new")
		{
			cin>>n1;
			mh[n1]=list<int>();
		}
		else if(cmd=="add")
		{
			cin>>n1>>n2;
			(mh[n1]).push_back(n2);
		}
		else if(cmd=="out")
		{
			cin>>n1;
			mh[n1].sort();
			for(list<int>::iterator x=mh[n1].begin();x!=mh[n1].end();++x)
			{
				cout<<*x<<" ";
			}
			cout<<endl;
		}
		else if(cmd=="merge")
		{
			cin>>n1>>n2;
//			if(n1!=n2)
			mh[n1].merge(mh[n2]);
		}
		else if(cmd=="unique")
		{
			cin>>n1;
			mh[n1].sort();
			mh[n1].unique();
		}
	}
	return 0;
}

