#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
	auto funcp=less<int>();
	cout<<funcp(9,10);
	return 0;
}

