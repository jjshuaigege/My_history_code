#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T* b,T* e)
{
	T temp=*b;
	for(T* x=b+1;x!=e;x++)
	{
		temp+=*x;
	}
	return temp;
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //??:1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
}

