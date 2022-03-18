#include <iostream>
#include <map>
using namespace std;
ostream& operator<<(ostream& o,pair<string,string> p)
{
	o<<"("<<p.first<<":"<<p.second<<")";
	return o;
}
int main()
{
	map<string,string> h;
	h["jiuba"]="shenguozhi";
	h["sishi"]="zhangrui";
	h["sanshi"]="likuwu";
	string s=h["anonymous"];
	for(map<string,string>::iterator p=h.begin();p!=h.end();p++)
	{
		cout<<*p<<endl;
	}
	cout<<"s="<<s<<endl;
	return 0;
}

