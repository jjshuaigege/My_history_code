//���캯���ĳ�ʼ���͸�ֵ������ 
#include <iostream>
using namespace std;
class A
{
	private:
		float x,y;
	public:
		A():y(1.1),x(2.2){};
		friend int main();
};
int main()
{
	A a;
	cout<<"a.x="<<a.x<<endl<<"a.y="<<a.y<<endl;
	return 0;
}

