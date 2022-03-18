#include <iostream>
using namespace std;
int main()
{
	enum color {red,blue,yellow=5,orange};
	color h;
	h=blue;
	cout<<(0==red)<<endl;
	cout<<(h==1)<<endl;
	cout<<orange<<endl;
	return 0;
}

