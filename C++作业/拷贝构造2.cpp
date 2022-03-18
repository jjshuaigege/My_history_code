#include <iostream>
#include <string.h>
using namespace std;
int obcnt=0;
class HowMany
{
	public:
		int i;
		HowMany(){obcnt++;print("HowMany()");}
		HowMany(int i):i(i){obcnt++;cout<<"i="<<this->i<<" ";print("HowMany(int i)");}
		HowMany(const HowMany& h){obcnt++;print("HowMany(HowMany& h)");}       //拷贝构造函数的形式为A::A(const A& T) 
		void print(const string& msg)
		{
			if(msg.size()!=0)cout<<msg<<":";
			cout<<"obcnt="<<obcnt<<endl;
		}
		~HowMany(){obcnt--;print("~HowMany()");}
};
HowMany f(HowMany h)
{
	cout<<"begin of f"<<endl;
	h.print("h argument inside f");
	cout<<"end of f"<<endl;
	return h;
}
int main()
{
	HowMany h1;
	h1.print("before f");
	HowMany h2=f(h1);
	h1.print("after f");
	return 0;
}

