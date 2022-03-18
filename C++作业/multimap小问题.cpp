#include <iostream>
#include <map>
using namespace std;
typedef multimap<int,int>::iterator MMI;
void print(MMI s,MMI e)
{
	for(MMI x=s;x!=e;++x)
	cout<<"("<<x->first<<","<<x->second<<")"<<endl;
}
int main()
{
	multimap<int,int> mmh;
	int n,n1,n2;
	cin>>n;
	MMI s0,e0;
	mmh.insert(pair<int,int>(1000000000,1));
	for(int i=0;i<n;++i)
	{
		cin>>n1>>n2;   //n1为序号，n2为实力 
		s0=mmh.lower_bound(n2)==mmh.end()?mmh.begin():mmh.lower_bound(n2);
		e0=mmh.upper_bound(n2);
		cout<<"---------"<<endl;
		cout<<s0->first<<endl;
		cout<<e0->first<<endl;
		cout<<"---------"<<endl;
		MMI obj=s0;
		for(MMI x=s0;x!=e0;++x)
		{
			if(abs(obj->first-n2)>abs(x->first-n2))
			{
				obj=x;
			}
			else if(abs(obj->first-n2)==abs(x->first-n2))
			{
				if(obj->second>x->second)
				{
					obj=x;
				}
			}
		}
		cout<<"best opponent:"<<obj->second<<endl;
		mmh.insert(pair<int,int>(n2,n1));
		print(mmh.begin(),mmh.end());
	}
	return 0;
}

