#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
	int x=8;
	double y=3.14;
	int z1=5;
	int z2=6;
	//����lambda���ʽ��[]�涨���Է��ʵ�lambda�����ⲿ�ı���  
	cout<<[&z1](double a,double b)
	{
		cout<<z1<<endl;
		return a+b;
	}(2.13,3.56)<<endl; 
	//����һ�������ֵ�lambda������[]�涨���Է��ʵ�lambda�����ⲿ�ı��� 
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

