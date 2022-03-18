#include <iostream>
using namespace std;
class A
{
	protected:
		int i,k;
	public:
		A():i(10){}
//		virtual void print(){cout<<"A::print()"<<endl;}
		virtual void print(){cout<<"A::print(),i="<<i<<endl;}
		
};
class B:public A
{
	private:
		int j;
	public:
		B():j(30){i=20;}
//		virtual void print(){cout<<"B::print()"<<endl;}
		virtual void print(){cout<<"B::print(),i="<<i<<" "<<"j="<<j<<endl;}
		virtual void hw(){cout<<"hello,world!"<<endl;}
};
class C
{
	protected:
		int i;
	public:
		C():i(10){}
		
};
class D:public C
{
	protected:
		int j;
	public:
		D():j(20){}
};
void print(A* a)
{
	a->print();
}
int main()
{
	A a;
	A a2;
	B b;
	C c;
	D d;
	cout<<"sizeof(A)="<<sizeof(A)<<endl<<"sizeof(B)="<<sizeof(B)<<endl<<"sizeof(c)="<<sizeof(c)<<endl<<"sizeof(d)="<<sizeof(d)<<endl;
	int *r=(int *)&a;
	int *s=(int *)&a2;
	cout<<"*r="<<*r<<endl<<"*s="<<*s<<endl;   // 说明同一个类共用同一张Vtable 
	print(&a);
	print(&b);
//	A* p1=&a;
//	B* p2=&b;
//	p1=p2;
//	cout<<sizeof(*p1)<<endl<<sizeof(*p2)<<endl;
	a=b;
	a.print();
	print(&a);
	int *p=(int*)&a;
	int *q=(int*)&b;
	*p=*q;  //务必为32位寻址方式
	print(&a);  
	return 0;
}

