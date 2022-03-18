#include <iostream>
using namespace std;
class A
{
	private:
		int i,j;
	public:
		A();
		int add();
		int minus();
};
inline int A::add()
{
	return (i+j);
}
inline int A::minus()
{
	return(i-j);
}
inline A::A():i(20),j(25)
{
}
int main()
{
	A a;
	int o1,o2;
	o1=a.add();
	o2=a.minus();
	cout<<"o1="<<o1<<" "<<"o2="<<o2<<endl;	
	return 0;
}

