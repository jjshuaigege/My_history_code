#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool mycompare (int x1,int x2)
{
	return x1<x2;
}
int main()
{
	vector<int> a;
	a.push_back(12);
	a.push_back(16);
	a.push_back(18);
	a.push_back(8);
	a.push_back(19);
	sort(&a.at(0),&a.at(a.size()-1),mycompare);
//	vector::iterator ap;
	for(int i=0;i<a.size();i++)
	cout<<a.at(i)<<endl;
	return 0;
}
