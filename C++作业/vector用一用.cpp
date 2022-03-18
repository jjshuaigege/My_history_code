#include <iostream>
#include <vector>
using namespace std;
template<class T>
void PrintVector(T s,T e)
{
	for(;s!=e;s++)
	{
		cout<<*s<<" ";
	}
	cout<<endl;
}
int main()
{
	int a[5]={1,2,3,4,5};
	vector<int> h1{a,a+5};
	PrintVector(h1.begin(),h1.end()); 
	vector<int> h2(4,20);
	PrintVector(h2.begin(),h2.end());
	h1.insert(h1.begin()+2,h2.begin(),h2.end()-1);
	PrintVector(h1.begin(),h1.end());
	h1.erase(h1.begin()+2,h1.begin()+5);
	PrintVector(h1.begin(),h1.end());
	vector<int> h3(8);
	PrintVector(h3.begin(),h3.end());
	vector<vector<int> > hh(7,vector<int>(10,1));
	for(int i=0;i<hh.size();++i)
	{
		for(int j=0;j<hh.at(i).size();++j)
		{
			cout<<hh.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
	return 0;
}

