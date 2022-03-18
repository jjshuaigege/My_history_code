#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool string_resort(string a,string b)
{
	if(a=="shx")
	{
		return true;
	}
	else if(a=="llh")
	{
		if(b=="shx")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
int main()
{
	vector<string> h;
	h.push_back("sgz");
	h.push_back("shx");
	h.push_back("llh");
	sort(h.begin(),h.end(),string_resort);
	for(string x:h)
	cout<<x<<endl;
	vector<string>::iterator x=h.begin();
	cout<<"==="<<endl<<*x<<endl;
	return 0;
}

