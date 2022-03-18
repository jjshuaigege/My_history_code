#include <iostream>
using namespace std;
template<class T1,class T2>
class A
{
	public:
	typedef double dou;
	public:
	class B
	{
		T1 a;
		T2 b;
		public:
		B():a(1),b(9.8)
		{
			
		}
		B(int a,double b):a(a),b(b)
		{
			
		}
		void show()
		{
			cout<<"("<<a<<","<<b<<")"<<endl;
		}
	};
};
template<typename T1,typename T2>
PrintA(const A<T1,T2> &x)
{
	typename A<T1,T2>::B i;
}
int main()
{
	A<int,double> x;
	PrintA(x);
	A<int,double>::dou d=3.14;
	cout<<d<<endl;
	return 0;
}

