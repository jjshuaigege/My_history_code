#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string::const_iterator i,j;
	i=find(s.cbegin(),s.cend(),'h');
	while(i!=s.cend())
	{
		cout<<(i-s.cbegin())<<" ";
		j=i+1;
		i=find(j,s.cend(),'h');
	}
	cout<<endl;
	return 0;
}

