#include <iostream>
using namespace std;
class A
{
	public:
		static int i;
	public:
		A(){i=520;}
		printp(){printf("this:%p\n",this);}
};
int A::i=0;
int main()
{
	A a1,a2;
	a1.printp();
	a2.printp();
	cout<<A::i<<endl;
	return 0;
}

