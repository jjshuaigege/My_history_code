#include <iostream>
using namespace std;
class parent
{
	public:
		parent();
		~parent();
		void print();
		void spend_little();
	protected:
		void half();
	private:
		int money;	
};
class son:public parent
{
	public:
		void spend_given_by_parent_();
};
void parent::print()
{
	cout<<"money="<<money<<endl;
}
void parent::spend_little()
{
	money--;
}
void parent::half()
{
	money/=2;
}
void son::spend_given_by_parent_()
{
	half();
}
parent::parent():money(5000){cout<<"parent::parent"<<endl;}
parent::~parent(){cout<<"parent::~parent"<<endl;}
int main()
{
	son s;
	s.print();
	s.spend_given_by_parent_();
	s.print();
	return 0;
}

