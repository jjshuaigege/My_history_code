#include <iostream>
#include <ctime>
using namespace std;
class My_ostream
{
	public:
		My_ostream& operator << (My_ostream&(*x)(My_ostream& a))
		{
			return x(*this);
		}
		My_ostream& operator <<(const char* x)
		{
			cout<<x;
			return *this;
		}
}; 
My_ostream& myendl(My_ostream& a)
{
	a<<"\n";
	return a;
}
int main()
{
	My_ostream mycout;
	freopen("测试endl效率.txt","w",stdout);
	cout<<"开始！"<<endl;
	int c1=clock();
	for(int i=0;i<1000000;++i)
	{
		cout<<"\n";
		cout<<flush;
	}
	double t1=static_cast<double>(clock()-c1)/CLK_TCK;
	int c2=clock();
	for(int i=0;i<1000000;++i)
	{
		cout<<endl;
	}
	double t2=static_cast<double>(clock()-c2)/CLK_TCK;
	int c3=clock();
	for(int i=0;i<1000000;++i)
	{
		mycout<<myendl;
		cout<<flush;
	}
	double t3=static_cast<double>(clock()-c3)/CLK_TCK;
	clog<<"endl="<<t1<<endl<<"\\n="<<t2<<endl<<"myendl="<<t3<<endl;
	cout<<"结束!"<<endl;
	return 0;
}

