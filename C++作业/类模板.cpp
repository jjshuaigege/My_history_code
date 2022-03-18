#include <iostream>
using namespace std;
template <typename T1,typename T2>
class A
{
	private:
		T1 t1;
		T2 t2;
	public:
		A(T1 t1,T2 t2):t1(t1),t2(t2)
		{
			
		}
		void print()
		{
			cout<<"T1:"<<t1<<" "<<"T2:"<<t2<<endl;
		}
		//函数模板作为类的成员时，类可以有由这个模板派生出的多个函数 
		template <class T3>
		T3 func(T3 t3)
		{
			return t3/2;
		}
};
int main()
{
	const char* s="写点东西";
	A<const char*,double> a(s,3.14159);
	a.print();
	cout<<a.func<double>(5)<<endl;
	return 0;
}

