#include <iostream>
using namespace std;
template<typename T>
class A
{
	public:
	static int i;
	T value;
};
template<> int A<int>::i=10;
template<> int A<double>::i=20;
int main()
{
	A<int> a1;
	A<double> a2;
	cout<<a1.i;
	return 0;
}

