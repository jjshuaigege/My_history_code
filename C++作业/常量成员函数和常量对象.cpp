#include <iostream>
using namespace std;
class Sample
{
	public:
		Sample():value(100){}
		int value;
		int get_value() const;
		void func(){}
		
};
int Sample::get_value() const
{
//	value=0;   //������Ա���������޸Ķ�������� 
//	func();    //������Ա�������ܵ��÷ǳ�����Ա���� 
	cout<<"value="<<value<<endl;
	return value;
}
int main()
{
	const Sample s1;
//	s1.func();         //���������ܵ��÷ǳ�����Ա���� 
//	s1.value=100;      //���������޷����޸����е� 
	Sample s2;
	s2.get_value();
	return 0;
}

