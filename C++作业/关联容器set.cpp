#include <iostream>
#include <set>
using namespace std;
int main()
{
	set<int> h;
	h.insert(10);
	h.insert(20);
	h.insert(15);
	if(h.find(17.5)==h.end())
	{
		cout<<"Not found!"<<endl;
	}
	return 0;
}

