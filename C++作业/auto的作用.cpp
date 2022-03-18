#include <iostream>
#include <typeinfo>
using namespace std;
class myComplex
{
	int real;
	int image;
	public:
	myComplex(int real,int image):real(real),image(image)
	{
	}
	int operator +(int x)
	{
		return real+x;
	}
	friend ostream& operator<<(ostream& o,myComplex x);
	friend myComplex& operator +(int x1,myComplex& x2);
};
ostream& operator<<(ostream& o,myComplex x)
{
	o<<x.real<<","<<x.image;
}
myComplex& operator +(int x1,myComplex& x2)
{
	x2.real+=x1;
	return x2; 
}
template<typename T1,typename T2>
auto add(T1 t1,T2 t2)->decltype(t1+t2) //->�����������ķ���ֵ����,��decltype�ؼ��ֵ������ǣ�ִ����֮�󷵻������ڱ��ʽ��������� 
{
	return t1+t2;
} 
int main()
{
	myComplex mc(4,7);
	cout<<typeid(add(mc,9)).name()<<endl;
	myComplex temp=add(25,mc);
	cout<<typeid(temp).name()<<endl;
	cout<<temp<<endl;
	//decltype���÷� 
	decltype(1.0) k=3.14;
	cout<<k<<endl;
	//����
	double l=2.8;
	decltype((l)) r=k;
	r=2.2;
	cout<<k<<endl;
	return 0;
}

