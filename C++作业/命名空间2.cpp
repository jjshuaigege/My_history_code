#include <iostream>
using namespace std;
namespace A
{
	int i=10;
	namespace B
	{
		void B_print1_i(){cout<<i<<endl;}
		int i=20;
		void B_print2_i(){cout<<i<<endl;}
		int j=30;
	}
	void A_print_j(){cout<<B::j<<endl;}
}
int main()
{
	A::A_print_j();
	A::B::B_print1_i();
	A::B::B_print2_i();
	return 0;
}

