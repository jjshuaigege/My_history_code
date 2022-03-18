#include <iostream>
using namespace std;
class Father
{
	private:
		int value;
	public:
		getValue()
		{
			return value;
		}
		Father():value(10)
		{
			
		}
};
class Son:public Father
{
	private:
		int value;
	public:
		get_sonValue()
		{
			return value;
		}
		Son():Father(),value(20)
		{
		
		}
		friend int main();
};
int main()
{
	Son s;
	cout<<s.value<<endl;
	cout<<s.getValue();
	return 0;
}

