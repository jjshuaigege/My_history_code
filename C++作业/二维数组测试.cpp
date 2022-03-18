#include <iostream>
using namespace std;
int main()
{
	int a[4][5]={1,2};
	int* p=a;
	cout<<*p<<endl;
	cout<<*(p+1)<<endl;
	return 0;
}

