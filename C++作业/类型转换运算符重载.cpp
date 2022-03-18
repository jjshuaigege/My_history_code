#include <iostream>
using namespace std;
class Complex
{
	private:
		double real;
		double image;
	public:
		Complex(double real,double image):real(real),image(image)
		{
			
		}
		~Complex()
		{
			
		}
		operator double()
		{
			return real;
		}
};
int main()
{
	Complex A(2.6,11.2);
	double n1;
	n1=A;
	cout<<n1<<endl;
	double n2;
	n2=A+6.6;
	cout<<n2<<endl;
	return 0;
}

