#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<int> a;
	a.push_back(4);
	a.push_back(2);
	a.push_back(3);
	a.push_back(1);
	vector<int>::iterator p=find(a.begin(),a.end(),3);
	if(p!=a.end())
	{
		cout<<"value found!location is "<<p-a.begin()<<endl;
	}
	else
	{
		cout<<"Not found!"<<endl;
	}
	//对于关联容器，其自身带有find方法，不用全局的find 
	
	return 0;
}

