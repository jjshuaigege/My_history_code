#include <iostream>
using namespace std;
class A
{
	public:
		void Hello()
		{
			cout<<"Hello"<<endl;
		}
};
int main()
{
	A* p=NULL;
	p->Hello();
	return 0;
}

