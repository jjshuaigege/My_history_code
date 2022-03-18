#include <iostream>
using namespace std;
class A
{
	private:
		const int i;
	public:
		A():i(20){}
		void f() const{cout<<"f() const"<<endl;}        //��ͬ��void f(const A* this) 
		void f(){cout<<"f()"<<endl;}                    //��ͬ��void f(A* this)
		void print() const{cout<<i<<endl;}
};
int main()
{
	A a1;
	const A a2;
	a1.f();
	a1.print();
	a2.f();
	a2.print();
	return 0;
}

