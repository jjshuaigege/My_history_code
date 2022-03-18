#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;
int main()
{
	cstring s1="shen,guo,zhi,shi,ge,da,shuai,ge";
	cstring s2="is";
	s1.replace(",",s2);
	cout<<s1<<endl;
	return 0;
}

