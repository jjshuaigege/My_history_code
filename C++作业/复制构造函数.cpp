#include <iostream>
using namespace std;
class Complex
{
	private:
	int image;
	int real;
	public:
	//���ƹ��캯�� 
	Complex(const Complex& x1)
	{
		real=x1.real;
		image=x1.image;
		cout<<"���ƹ��캯��������"<<endl;
	}
	//���캯��
	Complex(int a,int b)
	{
		real=a;
		image=b;
	}
	//��ӡ
	void print()
	{
		cout<<"image="<<image<<",";
		cout<<"real="<<real<<endl;	
	} 
};
void func(Complex cx)
{
	cout<<
}
int main()
{
	Complex c1(10,20);
	Complex c2=c1;     //�����������˸��ƹ��캯�� 
	
	c2.print();
	return 0;
}

