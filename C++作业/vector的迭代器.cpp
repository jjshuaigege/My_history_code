#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);
	vector<int>::const_iterator p1=a.begin();
	for(;p1!=a.end();p1++)
	{
		cout<<*p1<<" ";
	}
	cout<<endl;
	//反向迭代器，执行++操作是从后往前走 
	vector<int>::const_reverse_iterator p2=a.rbegin();
	for(;p2!=a.rend();p2++)
	{
		cout<<*p2<<" ";
	}
	cout<<endl;
	vector<int>::iterator p3=a.begin();
	for(;p3!=a.end();p3++)
	{
		*p3=99;
	}
	for(p1=a.begin();p1!=a.end();p1++)
	{
		cout<<*p1<<" ";
	}
	return 0;
}

