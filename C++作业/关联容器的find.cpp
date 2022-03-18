#include <iostream>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;
int main()
{
	//��������� 
	default_random_engine e(time(nullptr));    //��������棬��UTCΪ���� 
	cout<<e.min()<<" "<<e.max()<<endl;
	uniform_int_distribution<unsigned> u(0,1000);     //���ȷֲ�,��ΧΪ0��10000 
	set<int> s{1,99,54,61,3,2,5,8,46,123,999,988,998,997,996,995,994,993,992,991,990};
	for(auto i=s.cbegin();i!=s.cend();++i)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	int cmd;
	cin>>cmd;
	while(cmd!=-1)
	{
		set<int>::const_iterator ob1;
		auto s1=clock();
		for(int i=0;i<1000000;++i)
		{
			ob1=find(s.begin(),s.end(),u(e));		
		}
		double t1=static_cast<double>((clock()-s1))/CLK_TCK;
		cout<<"˳���������ʱ�䣺"<<t1<<endl;
		set<int>::const_iterator ob2;
		auto s2=clock();
		for(int i=0;i<1000000;++i)
		{
			ob2=s.find(u(e));	
		}
		double t2=(double)(clock()-s2)/CLK_TCK;
		cout<<"��������������ʱ�䣺"<<t2<<endl;
		if(ob1!=s.end())
		cout<<(*ob1)<<" ";
		else
		cout<<"δ�ҵ�"<<endl;
		if(ob2!=s.end())
		cout<<(*ob2)<<endl;
		else
		cout<<"δ�ҵ�"<<endl;
		cin>>cmd;	
	}
	
	return 0;
}

