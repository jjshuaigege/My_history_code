#include <iostream>
using namespace std;
template<typename T1,typename T2>
class A
{
	private:
		T1 key;
		T2 value;
	public:
		A(T1 key,T2 value):key(key),value(value)
		{
			
		}
		bool operator <(const A<T1,T2>& r) const;
};
template<typename T1,typename T2>
bool A<T1,T2>::operator <(const A<T1,T2>& r) const
		{
			return value<r.value;
		}
int main()
{
	A<const char*,int> a1("Mike",90);
	A<const char*,int> a2("Jack",89);
	cout<<(a1<a2)<<endl;
	cout<<(a2<a1)<<endl;
	return 0;
}

