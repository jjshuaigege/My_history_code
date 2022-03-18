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
	multimap<int,int> mmh;  //实力在前，序号在后 
	mmh.insert(pair<int,int>(1000000000,1));
	MMI lb,ub,s0,e0;
	int n;
	int n1,n2;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>n1>>n2;   //n1为序号，n2为实力 
		lb=mmh.lower_bound(n2);
		ub=mmh.upper_bound(n2);
		s0=lb;
		MMI x;
		for(x=lb;x!=mmh.begin();--x)
		{
			if(abs(s0->first-n2)<abs(x->first-n2))
			{
				break;
			}
			else
			{
				s0=x;
			}
		}
		if(x==mmh.begin())
		{
			if(abs(s0->first-n2)>=abs(x->first-n2))
			s0=x;
		}
		e0=ub;
		for(MMI x=ub;x!=mmh.end();++x)
		{
			if(abs(e0->first-n2)<abs(x->first-n2))
			{
				break;
			}
			else
			{
				e0=x;
			}
		}
		if(e0!=mmh.end())
		{
			++e0;
		}
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
//		cout<<"Output:"<<endl;
		cout<<n1<<" "<<(obj->second)<<endl;
		mmh.insert(pair<int,int>(n2,n1));
//		print(mmh.begin(),mmh.end());
//		cout<<"end of round"<<endl<<endl;
	}
	return 0;
}


