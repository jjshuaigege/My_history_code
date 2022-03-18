#include <iostream>
using namespace std;
class myexception1:public exception
{
	public:
		myexception1():exception(){}
		const char* what() const throw()      //声明不会抛出异常之后，编译器并不会检查这个函数是否真的没有抛出异常，得由使用者来保证 
		{
			return "发生了我的异常1，不能除以8\n";
		}
};
int main()
{
	while(true)
	{
		int a,b;
		cout<<"请输入a和b的值：\n";
		cin>>a>>b;
		try
		{
			if(b==8)
			{
				throw myexception1();
			}
			cout<<"a/b="<<a/b;
		}
		catch(myexception1 e)
		{
			cout<<e.what()<<endl;
		}
		catch(...)
		{
			cout<<"未知异常"<<endl;
		}		
	}
	return 0;
}

