#include <iostream>
using namespace std;
int main()
{
	//为什么有了malloc和free还要用new和delete？
	//1.因为C++有新的类，malloc和free对这些类不能起作用 
	//2.new和delete执行时会调用构造函数和析构函数，而malloc和free则不会 
	//第一种用法 （分配一个变量） 
	double *p=new double;
	*p=3.14159;
	cout<<*p<<endl;
	//第二种用法（分配一个数组） 
//	int *a=new int[100];
//	int a[100];
	int *a=(int* )malloc(sizeof(int)*100);
	for(int i=0;i<100;i++)
	{
		a[i]=i;	
	} 
	for(int i=0;i<100;i++)
	{
		cout<<a[i]<<endl;	
	} 
//	for(int i=0;i<sizeof(a)/sizeof(int);i++)
//	{
//		a[i]=i;	
//	} 
//	for(int i=0;i<sizeof(a)/sizeof(int);i++)
//	{
//		cout<<a[i]<<endl;	
//	} 
	return 0;
}

