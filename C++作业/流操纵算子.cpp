#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//控制进制的流操纵算子 
	int a=11;
	cout<<oct<<a<<endl;
	cout<<hex<<a<<endl;
//	cout<<bin<<a<<endl;
	cout<<15<<endl;
	cout<<dec<<a<<endl;
	//控制浮点数精度的流操纵算子
	double pi=3.14159;
	double x=1234567.89;
	//第一种方式 
	cout<<setprecision(5);
	cout<<pi<<endl; 
	cout<<x<<endl;
	//第二种方式
	cout.precision(4);
	cout<<pi<<endl; 
	//以小数点位置为起始，保留相应的有效位数(保留小数点后n位有效数字)
	cout<<setiosflags(ios::fixed);
	cout<<pi<<endl; 
	//取消 
	cout<<resetiosflags(ios::fixed)<<pi<<endl;
	//控制域宽的流操纵算子(一次性)
	cout<<setw(10)<<"1012"<<endl;
	cout.width(15);
	//左对齐 
	cout<<left<<"h"<<"g"<<endl;
	//
	cout<<fixed<<setprecision(6)<<3.1415926;
	return 0;
}

