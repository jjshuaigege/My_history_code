#include <iostream>
using namespace std;
//函数重载（函数的参数类型和个数不同，构成函数重载） 
double add(double a,int b)
{
	cout<<"执行double，int"<<endl;
	return a+b;
}
double add(double a,double b)
{
	cout<<"执行double，double"<<endl;
	return a+b;
}
double add(double a,double b,double c)
{
	cout<<"执行double，double，double"<<endl; 
	return a+b+c;
}
int add(int a,int b)
{
	cout<<"执行int,int"<<endl; 
	return a+b;
}
//缺省值 
void multiply(int a,int b=2,double c=3.3)
{
	cout<<"a*b*c="<<a*b*c<<endl;
}

int main()
{
	int a=1;
	double b=2.2;
	double c=3.3;
	cout<<add(b,a)<<endl;
	cout<<add(b,b,c)<<endl;
	cout<<add(b,c)<<endl;
	cout<<add(a,a)<<endl;
	multiply(4);
	multiply(4,3);
	multiply(4,3,3.7);
	
	return 0;
}

