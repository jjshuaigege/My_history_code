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
		cout<<"���ƹ��캯��������"<<endl;
	}
};
//���ƹ��캯�������õĵ�һ���������һ������ȥ��ʼ��ͬ�����һ������
 
//������ƹ��캯��δ�涨��Ա������ֵ����ôĬ��Ϊ0 
//���ƹ��캯�������õĵڶ������ 
void func(A a)
{
	cout<<"��func�У�a.a="<<a.a<<","<<"a.b="<<a.b<<endl;
}
//���ƹ��캯�������õĵ��������,�����ķ���ֵΪһ������ 
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

