#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n;
	string cmd;
	multiset<int> mh;
	set<int> doch;//记录曾经加入过的元素 
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int n1;
		cin>>cmd;
		if(cmd=="add")
		{
			cin>>n1;
			mh.insert(n1);
			doch.insert(n1);
			cout<<mh.count(n1)<<endl;	
		}
		else if(cmd=="ask")
		{
			cin>>n1;
			if(doch.find(n1)!=doch.end())
			{
				cout<<1<<" ";
			}
			else
			{
				cout<<0<<" ";
			}
			cout<<mh.count(n1)<<endl;
		}
		else if(cmd=="del")
		{			
			cin>>n1;
			cout<<mh.count(n1)<<endl;
			for(multiset<int>::iterator x=mh.begin();x!=mh.end();)
			{
				if(*x==n1)
				{
					multiset<int>::iterator temp=x;
					++x;
					mh.erase(temp);
				}
				else
				{
					++x;
				}
			}
		}
	}
	return 0;
}

