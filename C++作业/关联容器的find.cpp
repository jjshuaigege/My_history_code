#include <iostream>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;
int main()
{
	//产生随机数 
	default_random_engine e(time(nullptr));    //随机数引擎，以UTC为种子 
	cout<<e.min()<<" "<<e.max()<<endl;
	uniform_int_distribution<unsigned> u(0,1000);     //均匀分布,范围为0到10000 
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
		cout<<"顺序查找所花时间："<<t1<<endl;
		set<int>::const_iterator ob2;
		auto s2=clock();
		for(int i=0;i<1000000;++i)
		{
			ob2=s.find(u(e));	
		}
		double t2=(double)(clock()-s2)/CLK_TCK;
		cout<<"二叉树查找所花时间："<<t2<<endl;
		if(ob1!=s.end())
		cout<<(*ob1)<<" ";
		else
		cout<<"未找到"<<endl;
		if(ob2!=s.end())
		cout<<(*ob2)<<endl;
		else
		cout<<"未找到"<<endl;
		cin>>cmd;	
	}
	
	return 0;
}

