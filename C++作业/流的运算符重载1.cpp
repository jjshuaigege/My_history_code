#include <iostream>
using namespace std;
class CStudent
{
	public:int nAge;
};
ostream& operator<<(ostream& o,CStudent s)
{
	o<<s.nAge;
	return o;
}
int main()
{
	CStudent s;
	s.nAge=25;
	cout<<s<<endl;
	return 0;
}

