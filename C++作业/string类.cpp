#include <iostream>
#include <string>
//#<string.cpp>
using namespace std;
int main()
{
	std::string s1="shenguozhi";
	std::string s2="dashuaige";
	//字符串的赋值 
	s2.assign(s1,0,4);   //从s1的下标0开始，读取4个字符赋值给s2 
	//字符串的交换 
	swap(s1,s2);
	std::cout<<s1<<std::endl; 
	std::cout<<s2<<std::endl;
	//求子串 
	cout<<s2.substr(4,3)<<endl; 
	//找子串
	string s3="jiansheng";
	string s4="yasuo";
	cout<<s4.find("suo")<<endl;
	//删除子串
	s3.erase(4,2);    //从下标四开始删除两个字符 
	cout<<s3<<endl; 
	return 0;
}

