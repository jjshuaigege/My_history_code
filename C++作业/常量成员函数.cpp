#include <iostream>
using namespace std;
class Sample
{
	private:
		int value;
	public:
		int get_value() const;
		void func();
		
};
int Sample::get_value() const
{
	value=0;   //������Ա���������޸Ķ�������� 
	func();    //������Ա�������ܵ��÷ǳ�����Ա���� 
	return value;
}
int main()
{
	return 0;
}

