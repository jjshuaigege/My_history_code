#include <iostream>
#include <vector>
//问题未解决！！ 
using namespace std;
class A
{
	int a;
	int b;
	public:
		A(int a):a(a),b(a)
		{
			
		}
		friend ostream& operator <<(ostream& o,const A x);
};
ostream& operator <<(ostream& o,const A x)
{
	o<<x.a<<","<<x.b<<endl;
	return o;
}
int main()
{
	int a[][2]={
				{3,6},
				{4,5},
				{5,10},
				{6,11},
				{15,9},
					};
	vector<A> h(*a,*(a+5));
	for(A x:h)
	{
		cout<<x;
	}	
	return 0;
}

