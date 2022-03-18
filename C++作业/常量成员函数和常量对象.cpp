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
//	value=0;   //常量成员函数不能修改对象的内容 
//	func();    //常量成员函数不能调用非常量成员函数 
	cout<<"value="<<value<<endl;
	return value;
}
int main()
{
	const Sample s1;
//	s1.func();         //常量对象不能调用非常量成员函数 
//	s1.value=100;      //常量对象无法被修改其中的 
	Sample s2;
	s2.get_value();
	return 0;
}

