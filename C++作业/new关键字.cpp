#include <iostream>
using namespace std;
int main()
{
	//Ϊʲô����malloc��free��Ҫ��new��delete��
	//1.��ΪC++���µ��࣬malloc��free����Щ�಻�������� 
	//2.new��deleteִ��ʱ����ù��캯����������������malloc��free�򲻻� 
	//��һ���÷� ������һ�������� 
	double *p=new double;
	*p=3.14159;
	cout<<*p<<endl;
	//�ڶ����÷�������һ�����飩 
//	int *a=new int[100];
//	int a[100];
	int *a=(int* )malloc(sizeof(int)*100);
	for(int i=0;i<100;i++)
	{
		a[i]=i;	
	} 
	for(int i=0;i<100;i++)
	{
		cout<<a[i]<<endl;	
	} 
//	for(int i=0;i<sizeof(a)/sizeof(int);i++)
//	{
//		a[i]=i;	
//	} 
//	for(int i=0;i<sizeof(a)/sizeof(int);i++)
//	{
//		cout<<a[i]<<endl;	
//	} 
	return 0;
}

