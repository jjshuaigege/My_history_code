#include <iostream>
using namespace std;
//template<typename T1,typename T2>
//class Pair;
//template<typename T1,typename T2>
//ostream& operator<<(ostream& o,Pair<T1,T2>);
template<typename T1,typename T2>
class Pair
{
	private:
		T1 key;
		T2 value;
	public:
		Pair(T1 key,T2 value):key(key),value(value)
		{
			
		}
		template<typename T3,typename T4>
		friend ostream& operator<<(ostream& o,Pair<T3,T4>);
};
template<typename T1,typename T2>
ostream& operator<<(ostream& o,Pair<T1,T2> p)
{
	cout<<"("<<p.key<<":"<<p.value<<")";
	return o; 
}
int main()
{
	Pair<const char*,int> s("shenguozhi",98);
	Pair<int,double> s1(12,3.56);  
	cout<<s<<endl;
	cout<<s1;
	return 0;
}

