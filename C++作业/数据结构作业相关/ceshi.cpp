#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
int main()
{
	int time[8]={0};
	int loc=4;
	for(int t=0;t<99;++t)
	{
			cout<<"第"<<t<<"次:"<<endl;
			default_random_engine e(5016+t);//1021275376 1021224955
		//	cout<<e()<<endl;
			uniform_int_distribution<unsigned> u(0,7);
			for(int i=0;i<5;++i)
			{
				int temp=u(e);
				cout<<temp<<"\t";
				if(i==loc)
				{
					time[temp]++;	
				}	
			}
			cout<<endl;
		//	cout<<e()<<endl;
		//	uniform_int_distribution<unsigned> u(0,7);
		//	cout<<u(e)<<endl;
		//	cout<<u(e)<<endl;	
	}
	cout<<"在第"<<loc<<"个位置:"<<endl;
	for(int i=0;i<8;++i)
	{
		cout<<"出现"<<i<<" "<<time[i]<<"次"<<endl;
	}
	return 0;
}

