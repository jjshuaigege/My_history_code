#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout<<round(22.5)<<endl;
	cout<<round(23.5)<<endl;
	cout<<1.74689784<<endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<1.74689784<<endl;
	cout.unsetf(ios::fixed);
	cout.precision(6);
	cout<<1.74689784<<endl;
	return 0;
}

