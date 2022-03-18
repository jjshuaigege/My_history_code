#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T1,typename T2>
class A
{
	private:
	T1 v1;
	T2 v2;
//	A(T1 v1,T2 v2):v1(v1),v2(v2)
//	{
//		
//	}
	public:
		void print_type()
		{
			cout<<typeid(v1).name()<<" "<<typeid(v2).name()<<endl;
		}
};
template<typename T1,typename T2>
class B:public A<T2,T1>
{
	private:
	T1 v3;
	T2 v4;
	public:
//	B(T1 v1)
	void print_type()
	{
		cout<<typeid(v3).name()<<" "<<typeid(v4).name()<<endl;
	}
};
int main()
{
	//需要告诉编译器如何实例化 
	B<int,double> b;
	b.print_type();
	b.A::print_type();
	return 0;
}

