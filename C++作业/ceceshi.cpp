#include <iostream>
using namespace std;
union A
{
	
}
int main()
{
	int* p=reinterpret_cast<int*>(1);
	p++;
	long long n=reinterpret_cast<long long>(p);
	cout<<sizeof(int)<<endl;
	cout<<p<<endl;
	cout<<n<<endl;
	return 0;
}

