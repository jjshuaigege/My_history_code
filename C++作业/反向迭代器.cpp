#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
int main()
{
	vector<int> h{1,3,5,7,9,11,13,15};
	auto i=h.cbegin();     //cbeing()返回一个const的iterator 
	vector<int>::const_reverse_iterator j=h.crbegin();
	j++;
	i=j.base();    //使用成员函数base将反向迭代器转化为正向迭代器(正向迭代器在反向迭代器对应的位置后面一个单位)
	i--;
	cout<<"*i="<<*i<<endl;
	vector<int>::const_reverse_iterator k{i};    //反向迭代器用正向迭代器初始化 
	k++; 
	cout<<"*i="<<*i<<endl;
	j=(vector<int>::const_reverse_iterator)i;    //也可通过强制类型转化把反向转成正向   正、反向迭代器的位置同前（相隔一个单位） 
	cout<<*k<<endl;     
	cout<<*j<<endl;
	return 0;
}

