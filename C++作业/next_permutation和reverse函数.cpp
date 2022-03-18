#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s="123";
	int times=1;
	for(int i=1;i<=s.size();++i)
	{
		times*=i;
	}
	for(int i=0;i<times;++i)
	{
		next_permutation(s.begin(),s.end());
		cout<<s<<endl;
	}
	return 0;
}

