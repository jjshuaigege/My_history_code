#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[10]={15,16,89,56,13,65,15,103,158,54};
	sort(a,a+10,[](int x1,int x2)->bool{return x1%10<x2%10;});
	for(int x:a)
	{
		cout<<x<<endl;
	}
	return 0;
}

