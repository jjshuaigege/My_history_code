#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
int main()
{
	int time[8]={0};
	int loc=0;
	for(int t=0;t<99;++t)
	{
			cout<<"��"<<t<<"��:"<<endl;
			mt19937 e(5016+t);//1021275376 1021224955
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
	cout<<"�ڵ�"<<loc<<"��λ��:"<<endl;
	for(int i=0;i<8;++i)
	{
		cout<<"����"<<i<<" "<<time[i]<<"��"<<endl;
	}
	return 0;
	return 0;
}

