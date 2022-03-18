#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
	int a=35;
	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout<<a<<endl;
	cout.unsetf(ios::hex);
	cout.setf(ios::dec);
	cout<<a<<endl; 
	cout<<typeid(a).name()<<endl;
	return 0;
}

