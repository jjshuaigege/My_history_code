#include <iostream>
#include <vector>
#include <string>
using namespace std;
class A
{
	public:
		int n;
		const char Dy[8]={-1,0,1,-1,1,-1,0,1};
		const char Dx[8]={-1,-1,-1,0,0,1,1,1};
//		vector<vector<bool> > attack;
//		vector<vector<string> >solve;
		vector<string> Queen;
};
int main()
{
	A a;
	string s1="sgz";
	string s2=s1;
	s2="SGZ";
	cout<<s1<<endl;
	cout<<sizeof(a)<<endl;
	return 0;
}

