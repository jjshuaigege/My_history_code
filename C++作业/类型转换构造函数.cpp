#include <iostream>
using namespace std;
class A
{
	public:
		int x;
		double y;
		A(int x)         
		{
			cout<<"����ת�����캯��������"<<endl;
			this->x=x;
			this->y=0;
		}
		A(int x,double y)
		{
			this->x=x;
			this->y=y;
		}
			
};
int main()
{
	A a1(88,99);
	cout<<"x="<<a1.x<<","<<"y="<<a1.y<<endl;
	a1=80;    //�˴���80��ת����һ����ʱ��A����.
	//������̣����û�ж�Ӧ�ĸ�ֵ��������أ���ô��������ת�����캯�������ã�80ת����A��һ����ʱ����
	//������һ����Ķ���֮��ĸ�ֵ���������ã����ûд������Ĭ�ϵģ� 
	cout<<"x="<<a1.x<<","<<"y="<<a1.y<<endl;
	A a2(666);
	cout<<"x="<<a2.x<<","<<"y="<<a2.y<<endl;
	A a3=573.6;
	cout<<"x="<<a3.x<<","<<"y="<<a3.y<<endl;
	return 0;
}

