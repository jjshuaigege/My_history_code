#include <iostream>
using namespace std;
//#include <stdio.h>
int add(int i=1,int j=3)
{
	return (i+j);
}
int main()
{
	int num=add();
	cout<<num<<endl;
//	printf("%d",num);
	return 0;
}

