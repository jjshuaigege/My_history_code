#include <iostream>
#include "Procedure.h"
using namespace std;
int now_time=0;
int main()
{
	int n;
	int v,c,k,T;
	int v1,v2,v3,v4,v5;
	int f1,f2,f3,f4,f5;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		now_time=0;
		cin>>v;
		cin>>c>>k>>T;
		cin>>v1>>v2>>v3>>v4>>v5;
		cin>>f1>>f2>>f3>>f4>>f5;
		cout<<"Case:"<<i<<endl;
		Procedure p(v,v1,v2,v3,v4,v5,f1,f2,f3,f4,f5,c,k,T);
		p.begin();
	}  
	return 0;
}
