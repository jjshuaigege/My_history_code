#include <iostream>
using namespace std;
class Sample
{
	public:
		int value;
		Sample(int value):value(value){}
		//以下两个函数构成重载关系 
		int getvalue() const
		{
			cout<<"2*value="<<2*value<<endl;
			return 2*value;
		} 
		int getvalue()
		{
			cout<<"value="<<value<<endl;
			return value;
		}
};
int main()
{
	const Sample s1(250);
	Sample s2(360);
	s1.getvalue();
	s2.getvalue();
	return 0;
}

