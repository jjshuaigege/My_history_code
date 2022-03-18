#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a[10]={0,4,6,12,46,13,456,42,12,45};
	vector<int> h(a,a+5);
	for(int i:a)
	{
		cout<<i<<endl;
	}
	cout<<"----------"<<endl;
	for(int& i:h)
	{
		i=99;
	}
	for(int i:h)
	{
		cout<<i<<endl;
	}
	return 0;
}

