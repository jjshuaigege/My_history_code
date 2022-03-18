#include <iostream>
#include <algorithm>
using namespace std;
void func(int i)
{
	cout<<i*i<<endl;
}
int main()
{
	int a[]={5,3,1,6,49,1,65,13,46,13,};
	for_each(a,a+10,func);
	return 0;
}

