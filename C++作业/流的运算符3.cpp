#include <iostream>
using namespace std;
class Complex
{
	private:
		double real;
		double image;
	public:
		Complex():real(0),image(0)
		{
		}
		double& Get_real()
		{
			double& r=real;
			return r;
		}
		double& Get_image()
		{
			return image;
		}
		void print()
		{
			cout<<"real="<<real<<","<<"image="<<image;
		}
		friend istream& operator>>(istream& o,Complex& c);
	
};
ostream& operator<<(ostream& o,Complex& c)
{
	cout<<c.Get_real()<<"+"<<c.Get_image()<<"i";
	return o;
}
istream& operator>>(istream& o,Complex& c)
{
	char ch;
	cin>>c.Get_real()>>ch>>c.Get_image()>>ch;
	return o;
}
int main()
{
	Complex c;
	int n;
	cin>>c>>n;
	cout<<c<<","<<n;
	return 0;
}

