#include <iostream>
using namespace std;
void f(int i,int j=10,int k=20);
void f(int i,int j,int k)
{
	cout<<i<<" "<<j<<" "<<k<<endl;	
} 
int main()
{
	f(20,30);
	f(100,120,140);
	f(20);
	return 0;
}

