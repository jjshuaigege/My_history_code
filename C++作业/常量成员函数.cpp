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
	value=0;   //常量成员函数不能修改对象的内容 
	func();    //常量成员函数不能调用非常量成员函数 
	return value;
}
int main()
{
	return 0;
}

