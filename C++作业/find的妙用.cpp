#include <iostream>
#include <algorithm>
using namespace std;
class Print
{
	string s;
	public:
		Print(const char* x):s(x)
		{
			
		}
		operator==(const Print& x)
		{
			cout<<s<<",";
			return false;
		}
};
int main()
{
	vector<Print> h{"Shen","Guo","zhi"};
	find(h.begin(),h.end(),"dasd");
	return 0;
}

