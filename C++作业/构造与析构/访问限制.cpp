//访问权限三种    public（所有类或者结构可以访问） private(同一个类或者结构的成员函数可以访问 ) protect（同类和派生可以访问,结构同理）          
//friend     //friend写在public还是private并不影响；frined对象可以是一整个class，可以是一个class的member function，也可以是global function 
#include <iostream>
using namespace std;
struct A;     //前向声明(不完整的声明)，因为A和B要相互使用 
struct B
{
	void f(A*);
};
struct C
{
	void f(A*);
};
struct A
{
	private:
		friend struct C;      //another entire class or struct
		int i;
	public:
		A();
		friend void g(A*);      //global function
		friend void B::f(A*);        //member function
		~A();
};
void B::f(A* p)
{
	cout<<"B::f(A* p),p->i="<<p->i<<endl;
}
void C::f(A* p)
{
	cout<<"C::f(int n),p->i="<<p->i<<endl;
}
A::A()
{
	i=8;
}
A::~A()
{
	;
}
void g(A* p)
{
	cout<<"g(int n),p->i="<<p->i<<endl;	
}
int main()
{
	A a;
	B b;
	C c;
	g(&a);
	b.f(&a);
	c.f(&a);
}
