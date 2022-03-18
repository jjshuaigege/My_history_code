#include <iostream>
using namespace std;
class Moneycount
{
	private:
		int count;
		friend class Father;
	public:
		operator int()
		{
			return count;
		}
};
class Father
{
	protected:
		int value;
		Moneycount mc;
	public:
		Father(int value=0):value(value),mc()
		{
			
		}
		void changevalue()
		{
			value=value*2;
		}
	
};
class Son:public Father
{
	public:
		Son(int value=0):Father(value)
		{
			
		}
		//就算参数不一致，也是overwrite关系 
		void changevalue(int x)
		{
			value=value*x;
		}
		void showvalue()
		{
			cout<<"value="<<value<<endl;
		}
		void showcount()
		{
			cout<<"count="<<mc<<endl;	
		} 
};
int main()
{
	Son s(25);
	s.changevalue(6);
	s.showvalue();
	return 0;
}

