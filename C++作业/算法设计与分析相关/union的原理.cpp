#include <iostream>
//#include <cstdio>
using namespace std;
union A
{
	int i;
	unsigned char ch[sizeof(int)];
} a;
int main()
{
	a.i=1234;
	
	for(int i=0;i<sizeof(int);++i)
	{
		cout.unsetf(ios::dec);
		cout.setf(ios::hex|ios::uppercase);
		cout.precision(2);
		cout.width(2);
		cout.fill('0');
		cout<<static_cast<int>(a.ch[i])<<endl;
//		printf("%02hhX ",a.ch[i]);
	}
	cout.unsetf(ios::hex|ios::uppercase);
	cout.precision(6);
	cout.fill(' ');
	cout.setf(ios::dec);
	cout<<sizeof(bool)<<endl;
//	printf("\n"); 
	return 0;
}

