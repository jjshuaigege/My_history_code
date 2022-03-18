#include <iostream>
using namespace std;
class A
{
	public:
		int a;
		int b;
	public:
	A()
	{
		this->a=10;
		this->b=20;
	}
	A(int a,int b)
	{
		this->a=a;
		this->b=b;
	}
	A(A& a)
	{
		this->a=55;
		cout<<"复制构造函数被调用"<<endl;
	}
};
//复制构造函数起作用的第一种情况，用一个对象去初始化同类的另一个对象
 
//如果复制构造函数未规定成员变量的值，那么默认为0 
//复制构造函数起作用的第二种情况 
void func(A a)
{
	cout<<"在func中：a.a="<<a.a<<","<<"a.b="<<a.b<<endl;
}
//复制构造函数起作用的第三种情况,函数的返回值为一个对象 
A func2()
{
	A a(16,18);
	return a;
}

int main()
{
	A a1(11,12);
	func(a1);
	cout<<"func2.a="<<func2().a<<endl;
	return 0;
}

