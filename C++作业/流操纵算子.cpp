#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//���ƽ��Ƶ����������� 
	int a=11;
	cout<<oct<<a<<endl;
	cout<<hex<<a<<endl;
//	cout<<bin<<a<<endl;
	cout<<15<<endl;
	cout<<dec<<a<<endl;
	//���Ƹ��������ȵ�����������
	double pi=3.14159;
	double x=1234567.89;
	//��һ�ַ�ʽ 
	cout<<setprecision(5);
	cout<<pi<<endl; 
	cout<<x<<endl;
	//�ڶ��ַ�ʽ
	cout.precision(4);
	cout<<pi<<endl; 
	//��С����λ��Ϊ��ʼ��������Ӧ����Чλ��(����С�����nλ��Ч����)
	cout<<setiosflags(ios::fixed);
	cout<<pi<<endl; 
	//ȡ�� 
	cout<<resetiosflags(ios::fixed)<<pi<<endl;
	//������������������(һ����)
	cout<<setw(10)<<"1012"<<endl;
	cout.width(15);
	//����� 
	cout<<left<<"h"<<"g"<<endl;
	//
	cout<<fixed<<setprecision(6)<<3.1415926;
	return 0;
}

