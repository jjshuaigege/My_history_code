#include <iostream>
using namespace std;
class Basic
{
	protected:
		int Bvalue;
	public:
		Basic(int Bvalue):Bvalue(Bvalue)
		{
			
		}
		void show_value()
		{
			cout<<"in B show_value()"<<endl;
			cout<<"Bvalue="<<Bvalue<<endl;
		}
};
class Derived:public Basic
{
	public:
		int Dvalue;
	public:
		Derived(int Bvalue,int Dvalue):Dvalue(Dvalue),Basic(Bvalue)
		{
			
		}
		void show_value()
		{
			cout<<"in D show_value()"<<endl;
			cout<<"Bvalue="<<Bvalue<<endl;
			cout<<"Dvalue="<<Dvalue<<endl;
		}
		
};
int main()
{
//	Basic b0(56);
//	Derived d0(66,76);
//	b0=d0;
//	b0.show_value();
//	cout<<d0.Dvalue<<endl;
	Basic* p=NULL;
	Derived d0(66,76);
	p=&d0;
	p->show_value();
	return 0;
}

