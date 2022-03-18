#include <iostream>
#include <algorithm>
#include <ctime>
#include <iterator>
using namespace std;
template<class T>
PrintVector(const vector<T>& h)
{
	typename vector<T>::const_iterator i=h.begin();
	for(;i!=h.end();++i)
	{
		cout<<*i<<",";
	 } 
	 cout<<endl;
}
bool larger_than_4(int x)
{
	return x>4;
}
int main()
{
	default_random_engine e(time(nullptr));
	uniform_int_distribution<int> u(0,100);
	int a[]={0,1,2,3,4,5,6,7,8,9};
//	shuffle(a,a+10,e);                 //random_shuffle已经过时 
	for(int x:a)
	{
		cout<<x<<",";
	}
	cout<<endl;
	ostream_iterator<int> output(cout," ");     //需要包含头文件<iterator> 
	copy_if(a,a+10,output,larger_than_4);       //输出大于5的数 
	cout<<endl;
	vector<int> h(10);
	copy(a,a+10,h.begin());
	h.push_back(8);
	h.push_back(12);
	h.push_back(15);
	cout<<"vector:"<<endl;
	PrintVector(h);
	remove(h.begin(),h.end(),5);
	PrintVector(h);	
	sort(h.begin(),h.end());
	PrintVector(h);
	auto ii=unique(h.begin(),h.end());
	PrintVector(h);
	cout<<"有效元素个数："<<ii-h.begin()<<endl;
//	copy_backward(h.begin()+2,h.begin()+6,h.begin()+8);
//	for(auto i=h.begin();i!=h.end();++i)
//	{
//		cout<<*i<<",";
//	}
//	cout<<endl;
	return 0;
}

