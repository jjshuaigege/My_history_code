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
		//����ģ����Ϊ��ĳ�Աʱ��������������ģ���������Ķ������ 
		template <class T3>
		T3 func(T3 t3)
		{
			return t3/2;
		}
};
int main()
{
	const char* s="д�㶫��";
	A<const char*,double> a(s,3.14159);
	a.print();
	cout<<a.func<double>(5)<<endl;
	return 0;
}

