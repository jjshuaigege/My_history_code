#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
//算多项式 f(n)=a0+a1*x+a2*x^2+a3*x^3+...+an*x^n
//=((...((an*x+an-1)*x+an-2)*x+...+a1)*x+a0)

//现在假设a0=0,a1=1,...,an=n 
//第一种，一般算法 
double func1(double x,double a[],int n)
{
	double sum=0;
	for(int i=0;i<=n;++i)
	{
		sum+=a[i]*pow(x,i);
	}
	return sum;
}
//第二种算法，秦九韶算法
double  func2(double x,double a[],int n)
{
	double sum=a[n];
	for(int i=n;i>=1;--i)
	{
		sum=sum*x+a[i-1];
	}
	return sum;
}
void  test(double x,double* a,int n,double(*funcp)(double,double*,int))
{
	clock_t s,e;
	cout.precision(15);
	cout.setf(ios::fixed);
	s=clock();
	cout<<funcp(x,a,n)<<endl;
	for(int i=0;i<1000000;++i)
	funcp(x,a,n); 
	e=clock();
	double t=static_cast<double>(e-s)/CLK_TCK;
	cout<<"t:"<<t<<" s"<<endl;
} 
int main()
{
//	//函数指针第一种定义 
//	double(*fp)(double,int);
//	fp=func2;
//	cout<<fp(1.2,80)<<endl;
//	//函数指针第二种定义
//	typedef  double(*fp1)(double,int);
//	fp1 xx=func1;
//	cout<<xx(1.2,80)<<endl;
	double a[101];
	a[0]=1;
	for(int i=1;i<=100;++i)
	{
		a[i]=1/i;
	}
	test(1.1,a,100,func1);
	test(1.1,a,100,func2);
	return 0;
}

