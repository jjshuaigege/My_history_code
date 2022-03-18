#include <iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
template <class T>
void swap(T& t1,T& t2)
{
	T temp=t1;
	t1=t2;
	t2=temp;
}
int main()
{
	double a=3.14;
	double b=5.16;
	swap(a,b);
	cout<<"a="<<a<<" "<<"b="<<b<<endl;
	int c=4,d=5;
	swap(c,d);
	cout<<"c="<<c<<" "<<"d="<<d<<endl;
	return 0;
}
