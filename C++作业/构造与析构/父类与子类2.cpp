#include <iostream>
using namespace std;
class A
{
	private:
		int i;
	public:
		A():i(0){cout<<"A::A()"<<endl;}
		~A(){cout<<"~A::A()"<<endl;}
		void print(){cout<<"A::print() i="<<i<<endl;}
		void set(int ii){i=ii;}
	protected:
		void mutiply_two(){i*=2;}
};
class B: public A
{
	public:
		void use_MT(){mutiply_two();}
};
int main()
{
	B b;
	b.print();
	b.set(20);
	b.print();
//	b.mutiply_two;
	b.use_MT();
	b.print();	
	return 0;
}

