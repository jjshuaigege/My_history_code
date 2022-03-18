#include <iostream>
#include <map>
using namespace std;
int main()
{
	multimap<int,string> mmh;
	mmh.insert(pair<int,string>(1,"sgz"));
	mmh.insert(pair<int,string>(2,"daffsdz"));
	mmh.insert(pair<int,string>(1,"SGZ"));
	mmh.insert(pair<int,string>(3,"daffsdz"));
	for(multimap<int,string>::iterator x=mmh.begin();x!=mmh.end();++x)
	{
		if(x->first==1)
		{
			cout<<x->second<<endl;
		}
	}
	return 0;
}

