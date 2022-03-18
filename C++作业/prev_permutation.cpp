#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[]={1,2,3};
	prev_permutation(a,a+3);
	for(int i=0;i<sizeof(a)/sizeof(int);++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}

