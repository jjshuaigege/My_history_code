#include <iostream>
using namespace std;
template <class T1,class T2>
void print(T1 t1,T2 t2)
{
	cout<<t1<<" "<<t2<<endl;
}
int main()
{
	int i=99;
	const char* s="一个安静的程序员";
	print(i,s);
	return 0;
}

