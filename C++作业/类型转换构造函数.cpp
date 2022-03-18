#include <iostream>
using namespace std;
class A
{
	public:
		int x;
		double y;
		A(int x)         
		{
			cout<<"类型转换构造函数被调用"<<endl;
			this->x=x;
			this->y=0;
		}
		A(int x,double y)
		{
			this->x=x;
			this->y=y;
		}
			
};
int main()
{
	A a1(88,99);
	cout<<"x="<<a1.x<<","<<"y="<<a1.y<<endl;
	a1=80;    //此处是80被转换成一个临时的A对象.
	//具体过程：如果没有对应的赋值运算符重载，那么首先类型转换构造函数被调用，80转化成A的一个临时对象。
	//接着是一个类的对象之间的赋值函数被调用（如果没写，就是默认的） 
	cout<<"x="<<a1.x<<","<<"y="<<a1.y<<endl;
	A a2(666);
	cout<<"x="<<a2.x<<","<<"y="<<a2.y<<endl;
	A a3=573.6;
	cout<<"x="<<a3.x<<","<<"y="<<a3.y<<endl;
	return 0;
}

