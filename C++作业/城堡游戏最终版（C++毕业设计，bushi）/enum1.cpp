#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
	enum color{blue,red};
	class A
	{
		public:
			color camp; 
	};
	A a;
	a.camp=blue;
	cout<<a.camp<<endl;
	cout<<(typeid(blue)==typeid(color))<<endl; 
	return 0;
}

