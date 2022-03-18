#include <iostream>
using namespace std;
struct x
{
	int a;
	double b;
	double c;
};
int main()
{
	struct x k={5.5,2,8.8};
	cout<<k.a<<" "<<k.b<<" "<<k.c<<endl;
	return 0;
}

