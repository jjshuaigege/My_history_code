#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;
int main()
{
	string s="123";
	while(next_permutation(s.begin(),s.end()))
	{
		cout<<s<<endl;
	}
	int a[10]={9,8,7,6,5,4,3,2,1,0};
	sort(a,a+10);
	for(int i=0;i<10;i++)
	cout<<a[i]<<",";
	cout<<endl;
	vector<int> h(a,a+10);
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(h.begin(),h.end());
	//查看打乱后的结果 
	for(int x:h)
	{
		cout<<x<<",";
	}
	cout<<endl;
//	while(prev_permutation(h.begin(),h.end()))
//	{
//		for(int x:h)
//		{
//			cout<<x<<",";
//		}
//		cout<<endl;
//	}
	return 0;
}

