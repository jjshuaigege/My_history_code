#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
	int x=8;
	double y=3.14;
	int z1=5;
	int z2=6;
	//无名lambda表达式，[]规定可以访问的lambda函数外部的变量  
	cout<<[&z1](double a,double b)
	{
		cout<<z1<<endl;
		return a+b;
	}(2.13,3.56)<<endl; 
	//定义一个有名字的lambda函数，[]规定可以访问的lambda函数外部的变量 
	auto ff=[=,&x,&y](int n)->decltype(n*n)
	{
		cout<<z2<<","<<z1<<endl;
		x++;
		y++;
		n++;
		return n*n;
	};
	cout<<ff(16)<<endl;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
	cout<<typeid(ff).name();
	
	return 0;
}

