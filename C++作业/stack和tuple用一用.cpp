#include <iostream>
#include <stack>
#include <tuple>
#include <typeinfo>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <algorithm>
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
};
int mycompare(const void* a,const void* b)
{
	auto C1=reinterpret_cast<const Complex*>(a);
	auto C2=reinterpret_cast<const Complex*>(b);
	return pow(C1->real,2)+pow(C1->image,2)>pow(C2->real,2)+pow(C2->image,2);
}
bool mycompare1(const Complex& a,const Complex& b)
{
	return pow(a.real,2)+pow(a.image,2)<pow(b.real,2)+pow(b.image,2);
}
int main()
{
	cout<<endl;
	Complex* hh=reinterpret_cast<Complex*>(new char[5*sizeof(Complex)]);
	for(int i=0;i<5;++i)
	{
		new(hh+i)Complex(5-i,2*(5-i));
	}
	cout<<"before:"<<endl;
	for(int i=0;i<5;++i)
	{
		cout<<hh[i]<<endl;
	}
	qsort(hh,5,sizeof(Complex),mycompare);
	cout<<"after:"<<endl;
	for(int i=0;i<5;++i)
	{
		cout<<hh[i]<<endl;
	}
	sort(hh,hh+5,mycompare1);    //sort和qsort是反着排序的 
	cout<<"final:"<<endl;
	for(int i=0;i<5;++i)
	{
		cout<<hh[i]<<endl;
	}
	auto i=make_tuple(1,1.1,3);
	cout<<typeid(i).name()<<endl;
	stack<decltype(i)> h;
	h.push(i);
	h.push(make_tuple(2,1.1,3));
	h.push(make_tuple(3,1.1,3));
	h.push(make_tuple(4,1.1,3));
	decltype(i) buf=(h.top());
	h.top()=make_tuple(5,1.1,3);
	h.pop();
	cout<<h.size()<<endl;
	cout<<"("<<get<0>(buf)<<","<<get<1>(buf)<<","<<get<2>(buf)<<")"<<endl;
	cout<<"("<<get<0>(h.top())<<","<<get<1>(h.top())<<","<<get<2>(h.top())<<")"<<endl;
	return 0;
}

