#include <iostream>
#include <set>
using namespace std;
template<typename T1,typename T2,typename T3>
PrintSet(const multiset<T1,T2,T3> &x)
{
	typename multiset<T1,T2,T3>::iterator i;
	for(i=x.begin();i!=x.end();++i)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
}
int main()
{
	multiset<int> h={56,48,72,49,23,88,88,87,86,89,101};
	auto p=h.equal_range(88);
	auto n1=p.first;
	auto n2=p.second;
	cout<<*n1<<","<<*n2<<endl;
	PrintSet(h);
	cout<<h.count(88)<<endl;
	auto i2=h.erase(h.lower_bound(88),h.upper_bound(88));
	cout<<*i2<<endl;
	multiset<int> ms{1,8,8,8,9};
	multiset<int>::const_iterator ii1=ms.find(8);       //由此可验证，当multiset有多个相同元素时，找到的是第一个元素 
	multiset<int>::const_iterator ii2=ii1;
	ii1++;
	ii2--;
	cout<<"ii1="<<*ii1<<endl<<"ii2="<<*ii2<<endl;
	return 0;
}

