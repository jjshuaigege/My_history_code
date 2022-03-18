#include <iostream>
#include <map>
#include <string>
using namespace std;
template<class T1,class T2>
ostream& operator << (ostream& o,const pair<T1,T2> &p)
{
	o<<"("<<p.first<<","<<p.second<<")";
	return o;
}
int main()
{
	map<string,int> h;
	cout<<h["shenguozhi"]<<endl;
	h["zb"]=66;
	h["zac"]=55;
	for(auto i=h.begin();i!=h.end();++i)
	{
		cout<<"("<<i->first<<","<<i->second<<")"<<endl;
	}
	pair<map<string,int>::iterator,bool> i=h.insert(pair<string,int>("zb",77));
	if(i.second==true)
	cout<<*(i.first)<<"插入成功"<<endl;
	else
	{
		cout<<*(i.first)<<"插入失败"<<endl;
	}
	return 0;
}

