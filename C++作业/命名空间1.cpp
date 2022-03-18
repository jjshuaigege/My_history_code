#include <iostream>
using namespace std;
namespace std
	{
		int ii=10;
		namespace mynp
		{
			int ii=20;
		}
		int myfunc(int);
	}
//在命名空间外部定义一个函数
int std::myfunc(int i)
{
	return 2*i;	
} 
int main()
{
	cout<<ii<<endl;
	cout<<mynp::ii<<endl;
	cout<<myfunc(4)<<endl;
	return 0;
}

