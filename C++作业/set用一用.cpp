#include <iostream>
#include <set>
using namespace std;
class Complex
{
	private:
	int real;
	int image;
	friend int mycompare(const void* a,const void* b);
	friend bool mycompare1(const Complex& a,const Complex& b);
	friend class mycompare1;
	public:
		Complex(int real,int image):real(real),image(image)
		{
			
		}
		friend ostream& operator<<(ostream& o,const Complex& x)
		{
			o<<"("<<x.real<<","<<x.image<<")";
			return o;
		}
		bool operator < (const Complex& x) const
		{
			return real<x.real;	
		} 
//		bool operator==(const Complex& x)
//		{
//			return real==x.real&&image==x.image;	
//		} 
};
template<typename T1,typename T2,typename T3>
void PrintSet(const set<T1,T2,T3>& x)
{
	for(typename set<T1,T2,T3>::iterator i=x.begin();i!=x.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
}

class mycompare1
{
	public:
	bool operator()(const Complex& a,const Complex& b)       //定义了一个函数对象(只能这么用，不可以用函数指针代替！) 
	{
		return a.image<b.image;
	}	
};
//bool mycompare1(const Complex& a,const Complex& b)
//{
//	return a.image<b.image;
//}
int main()
{
	set<Complex> s1{Complex(3,4),Complex(2,1),Complex(6,8),Complex(1,9)};
	PrintSet(s1);
	set<Complex,mycompare1> s2{Complex(3,4),Complex(2,1),Complex(6,8),Complex(1,9)};
	PrintSet(s2);
	return 0;
}

