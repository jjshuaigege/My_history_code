#include <iostream>
using namespace std;
class Basic
{
	protected:
		int value;
	public:
		Basic(int value=0):value(value)
		{
			
		}
		int show_value()
		{
			cout<<"value="<<value<<endl;
		}
};
class Derived:public Basic
{
	private:
		int value;
	public:
		Derived(int Bvalue=0,int Dvalue=0):Basic(Bvalue),value(Dvalue)
			{
				
			}
		int show_value(int i)
		{
			cout<<"Basic::value="<<Basic::value<<endl;
			cout<<"value*i="<<value*i<<endl; 
		}
};
int main()
{
	Derived d(20,30);
	d.Basic::show_value();
	d.show_value(3);
	
	return 0;
}

