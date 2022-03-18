#include <iostream>
using namespace std;
class Complex
{
	private:
	int image;
	int real;
	public:
	//复制构造函数 
	Complex(const Complex& x1)
	{
		real=x1.real;
		image=x1.image;
		cout<<"复制构造函数被调用"<<endl;
	}
	//构造函数
	Complex(int a,int b)
	{
		real=a;
		image=b;
	}
	//打印
	void print()
	{
		cout<<"image="<<image<<",";
		cout<<"real="<<real<<endl;	
	} 
};
void func(Complex cx)
{
	cout<<
}
int main()
{
	Complex c1(10,20);
	Complex c2=c1;     //此条语句调用了复制构造函数 
	
	c2.print();
	return 0;
}

