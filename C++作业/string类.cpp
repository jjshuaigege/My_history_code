#include <iostream>
#include <string>
//#<string.cpp>
using namespace std;
int main()
{
	std::string s1="shenguozhi";
	std::string s2="dashuaige";
	//�ַ����ĸ�ֵ 
	s2.assign(s1,0,4);   //��s1���±�0��ʼ����ȡ4���ַ���ֵ��s2 
	//�ַ����Ľ��� 
	swap(s1,s2);
	std::cout<<s1<<std::endl; 
	std::cout<<s2<<std::endl;
	//���Ӵ� 
	cout<<s2.substr(4,3)<<endl; 
	//���Ӵ�
	string s3="jiansheng";
	string s4="yasuo";
	cout<<s4.find("suo")<<endl;
	//ɾ���Ӵ�
	s3.erase(4,2);    //���±��Ŀ�ʼɾ�������ַ� 
	cout<<s3<<endl; 
	return 0;
}

