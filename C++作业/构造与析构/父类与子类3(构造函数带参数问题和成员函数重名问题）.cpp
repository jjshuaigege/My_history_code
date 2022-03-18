#include <iostream>
using namespace std;
class A
{
	private:
		int i;
	public:
		A(int ii):i(ii){}
		void print(){cout<<"A::print()"<<endl;}
		void print(int ii){cout<<"A::print(int) i*"<<ii<<"="<<i*ii<<endl;}
}; 
class B:public A
{
	public:
	B(int ii):A(ii){}
	void prin(){cout<<"B::print()"<<endl;}
};
int main()
{
	B b(20);
	b.prin();
	b.print();
	b.print(30);
	return 0;
}

