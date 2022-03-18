#include <iostream>
using namespace std;
//设置一个模板实现字典功能 
template<class Tp,class funcp>
void map(Tp s,Tp e,Tp x,funcp f)
{
	for(;s!=e;s++,x++)
	{
		*x=f(*s);	
	}
} 
int square(int x)
{
	return x*x;	
}
double square(double x)
{
	return x*x;
}
int cube(int x)
{
	return x*x*x;	
} 
int main()
{
	double(*p1)(double)=square;
	int(*p2)(int)=square;
	double a1[5]={3.14,6.6,5.5,2.3,4.6};
	double a2[5];
	map(a1,a1+5,a2,p1);
	for(int i=0;i<sizeof(a1)/sizeof(double);i++)
	{
		cout<<a2[i]<<endl;
	}
	int b1[5]={3,6,5,2,4};
	int b2[5];
	map(b1,b1+5,b2,p2);
	for(int i=0;i<sizeof(b1)/sizeof(int);i++)
	{
		cout<<b2[i]<<endl;
	}
	
	return 0;
}

