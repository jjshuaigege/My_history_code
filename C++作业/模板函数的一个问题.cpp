#include <iostream>
using namespace std;
template<typename  T>
myswap(T* x1,T* x2)
{
	T temp=*x1;
	*x1=*x2;
	*x2=temp;
}
int main()
{
	double a1=9.9,a2=8.6;
	swap(a1,a2);
	cout<<a1<<","<<a2<<endl;
	return 0;
}

