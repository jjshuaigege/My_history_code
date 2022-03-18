#include <iostream>
//using namespace std;
namespace A
{
	int i=10;
	int func(){return 2*i;}
	class myclass
	{
		int i=10;
		public:
			void print()
			{
				std::cout<<"hello "<<i<<std::endl;
			}
	};
}
int main()
{
	int i=20;
	std::cout<<A::func()<<std::endl;
	std::cout<<A::i<<std::endl<<i<<std::endl; 
	A::myclass x;
	x.print();
	return 0;
}

