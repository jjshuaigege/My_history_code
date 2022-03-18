#include <iostream>
#include "Procedure.h"
using namespace std;
int now_time=0;
//输入格式:
//第一行代表游戏局数
//第二行依次代表双方基地生命元、基地之间有多少个城市、lion每前进一步其忠诚降低的数目，以及一局游戏的最高时长（分钟为单位）
//第三行依次代表dragon 、ninja、iceman、lion、wolf的生命元
//第四行依次代表dragon 、ninja、iceman、lion、wolf的攻击力 
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
