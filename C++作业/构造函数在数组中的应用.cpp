#include <iostream>
using namespace std;
class CSample
{
	public:
	CSample()
	{
		cout<<"constructor 1 called"<<endl;
	}
	CSample(int n)
	{
		cout<<"constructor 2 called"<<endl;
		cout<<"n="<<n<<endl;
	}
};
int main()
{
	CSample a1[2];
	CSample a2[2]={4,5};
	CSample a3[2]={0}; 
	CSample* a4=new CSample[2];
	CSample a5(56);
	cout<<"ÔÚÕâÍ£¶Ù"<<endl;
	CSample a6[3]={7,a5};
	delete[] a4; 
	return 0;
}

