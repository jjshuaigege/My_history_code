#include <iostream>
//#include <cstring>
using namespace std;
template<typename T1,typename T2>
class Mypair
{
	public:
		T1 first;
		T2 second;
	public:
		Mypair():first(),second()
			{
				cout<<"Mypair():first(),second() called"<<endl;
			}
		Mypair(const T1& first,const T2& second):first(first),second(second)
		{
			cout<<"Mypair(const T1& first,const T2& second):first(first),second(second) called"<<endl;
		}
		
		template<typename T3,typename T4>
		Mypair(const Mypair<T3,T4>& x):first(x.first),second(x.second)
		{
			cout<<"Mypair(const Mypair<T3,T4>& x):first(x.first),second(x.second) called"<<endl;
		}
};
class Mycomplex
{
	private:
		int real;
		int image;
	public:
		Mycomplex():real(0),image(0)
		{
			cout<<"Mycomplex():real(0),image(0) called"<<endl;
		}
		Mycomplex(int real,int image):real(real),image(image)
		{
			cout<<"Mycomplex(int,int) called"<<endl;
		}
		Mycomplex(const Mycomplex& x)
		{
			cout<<"Mycomplex copy called"<<endl;
			real=x.real;
			image=x.image;
		}
		friend ostream& operator<<(ostream& o,const Mycomplex& x);
};
ostream& operator<<(ostream& o,const Mycomplex& x)
{
	o<<"("<<x.real<<","<<x.image<<")"<<endl;
}
int main()
{
	Mypair<string,Mycomplex> mp1={"shenguozhi",{98,23}};
//	Mypair<string,Mycomplex> mp1("shenguozhi",Mycomplex(98,23));
	cout<<mp1.first<<endl<<mp1.second<<endl;
	Mypair<int,int> mp2(Mypair<double,double>(3.12,6.3));
	cout<<mp2.first<<endl<<mp2.second<<endl;
	return 0;
}

