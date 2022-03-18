#include <iostream>
#include <algorithm>
using namespace std;
bool mycompare(int a,int b)
{
	cout<<a<<"<"<<b<<"?"<<(a<b?"Õæ":"¼Ù")<<endl;
	return a<b;
 } 
int main()
{
	int a[7]={8,10,10,12,13,15,17};
	binary_search(a,a+7,10,mycompare);
	return 0;
}

