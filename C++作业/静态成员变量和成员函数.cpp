#include <iostream>
using namespace std;
class Rectangle
{
	private:
	int x;
	int y;
	static int totalnumber;     //只是声明，并未定义 
	static int totalarea;
	public:
		Rectangle(int x,int y):x(x),y(y)
		{
			totalnumber++;
			totalarea+=x*y;
		}
		~Rectangle()
		{
			totalnumber--;
			totalarea-=x*y;
		}
		static void init()
		{
			totalnumber=0;
			totalarea=0;
		}
		static void print()
		{
			cout<<"totalnumber="<<totalnumber<<endl;
			cout<<"totalarea="<<totalarea<<endl;
			
		}
};
int Rectangle::totalarea=0;    // 定义 
int Rectangle::totalnumber=0;

int main()
{
	Rectangle::init();
	Rectangle A(20,30);
	Rectangle B(40,55);
	A.print();
	Rectangle* p=NULL;
	p->print();
	Rectangle& r=A;
	r.print();
	return 0;
}

