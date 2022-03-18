#include <iostream>
using namespace std;
class A
{
	private:
		int a;
		double b; 
	public:
		A(int a,double b):a(a),b(b)
		{
			cout<<"a="<<a<<","<<"b="<<b<<endl;
		}
}; 
int main()
{
//	A t[5]={
//		{1,2.3}, 
//		{3,5.6},
//		{4,5.2},
//		{7,6.6},
//		{9,9.2},
//			};
//	A t[5]={A(1,2.3),A(3,5.6),A(4,5.2),A(7,6.6),A(9,9.2)};
	A t[5]={{1,2.3},{3,5.6},{4,5.2},{7,6.6},{9,9.2}};
	return 0;
}

