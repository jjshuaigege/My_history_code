//����Ȩ������    public����������߽ṹ���Է��ʣ� private(ͬһ������߽ṹ�ĳ�Ա�������Է��� ) protect��ͬ����������Է���,�ṹͬ��          
//friend     //friendд��public����private����Ӱ�죻frined���������һ����class��������һ��class��member function��Ҳ������global function 
#include <iostream>
using namespace std;
struct A;     //ǰ������(������������)����ΪA��BҪ�໥ʹ�� 
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
