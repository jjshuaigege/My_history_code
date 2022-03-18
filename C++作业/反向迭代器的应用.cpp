#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string s="shenguozhi";
	auto i=(find(s.rbegin(),s.rend(),'h'));
	auto j=i.base();
	cout<<*i<<endl;
	cout<<*j<<endl;
	return 0;
}

