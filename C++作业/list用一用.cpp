#include <iostream>
#include <list>
#include <cmath>
using namespace std;
class Complex
{
	int real;
	int image;
	friend int mycompare(const void* a,const void* b);
	friend bool mycompare1(const Complex& a,const Complex& b);
	public:
		Complex(int real,int image):real(real),image(image)
		{
			
		}
		friend ostream& operator<<(ostream& o,const Complex& x)
		{
			o<<"("<<x.real<<","<<x.image<<")";
			return o;
		}
		bool operator==(const Complex& x)
		{
			return real==x.real&&image==x.image;	
		} 
};
bool mycompare1(const Complex& a,const Complex& b)
{
	return pow(a.real,2)+pow(a.image,2)<pow(b.real,2)+pow(b.image,2);
}
template<typename T>
PrintList(T s,T e)
{
	for(;s!=e;++s)
	{
		cout<<*s<<" ";
	}
	cout<<endl;
	
}
int main()
{
	list<Complex> l{Complex(1,2.2),Complex(2,3.2),Complex(3,4.2),Complex(7,8.2),Complex(4,7.2),Complex(9,10.2),Complex(5,6.2),Complex(8,9.2),};
	l.sort(mycompare1);       //由于链表不支持随机访问，故需要用自身的成员函数sort进行排序 
	PrintList(l.begin(),l.end());
	l.reverse();
	PrintList(l.begin(),l.end());
	auto lt=l.end();
	lt--;
	l.insert(lt,Complex(9,10.2));
	PrintList(l.begin(),l.end());
	l.sort(mycompare1);
	PrintList(l.begin(),l.end());	
	l.unique();
	PrintList(l.begin(),l.end());
	list<Complex> ll{Complex(5,6),Complex(40,50)};
	l.merge(ll,mycompare1);     //在用到merge函数的排序时，前提条件需要ll是有序的！ 
	PrintList(l.begin(),l.end());
	return 0;
}

