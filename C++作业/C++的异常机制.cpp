#include <iostream>
using namespace std;
class myexception1:public exception
{
	public:
		myexception1():exception(){}
		const char* what() const throw()      //���������׳��쳣֮�󣬱���������������������Ƿ����û���׳��쳣������ʹ��������֤ 
		{
			return "�������ҵ��쳣1�����ܳ���8\n";
		}
};
int main()
{
	while(true)
	{
		int a,b;
		cout<<"������a��b��ֵ��\n";
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
			cout<<"δ֪�쳣"<<endl;
		}		
	}
	return 0;
}

