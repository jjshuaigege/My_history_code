#include <iostream>
#include "f.h"
using namespace std;
f::f(int n)
{
	i=n;
	cout<<"在构造函数中，处理前i="<<i<<endl;
	i++;
	cout<<"在构造函数中，处理后i="<<i<<endl;
}
f::~f()
{
	i=-1;
	cout<<"在析构函数中，i="<<i<<endl; 
}
