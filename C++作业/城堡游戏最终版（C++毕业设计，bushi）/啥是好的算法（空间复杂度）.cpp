#include <iostream>
#include <stdlib.h>
using namespace std;
void func1(int n)
{
	if(n)
	{
		func1(n-1);
		cout<<n<<endl;
	}
}
void func2(int n)
{
	for(int i=1;i<=n;++i)
	{
		cout<<i<<endl;
	}
}
int main()
{
	func2(100000);
	_sleep(1000);
	cout<<"continue!"<<endl;
	func1(100000);
	return 0;
}

