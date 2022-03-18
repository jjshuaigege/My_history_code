#include <iostream>
using namespace std;
template<class T>
T func(T t1,T t2)
{
	cout<<t1<<" "<<t2;
	return t1;
}
int main()
{
	func<double>(7.7,8);
	return 0;
}

