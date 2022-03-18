#include <iostream>
#include "f.h"
using namespace std;
void j(int num)
{
	if(num>10)
	goto e0;
	f(99);
	e0:f(55);
}
int main()
{
	int num;
	cin>>num;
	j(num);
	e0:cout<<"大括号前"<<endl;
	{
		f i(9);
		f ii(56);
	}
	cout<<"大括号后"<<endl;
}
