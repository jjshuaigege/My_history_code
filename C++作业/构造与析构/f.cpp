#include <iostream>
#include "f.h"
using namespace std;
f::f(int n)
{
	i=n;
	cout<<"�ڹ��캯���У�����ǰi="<<i<<endl;
	i++;
	cout<<"�ڹ��캯���У������i="<<i<<endl;
}
f::~f()
{
	i=-1;
	cout<<"�����������У�i="<<i<<endl; 
}
