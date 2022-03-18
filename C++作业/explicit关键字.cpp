#include <iostream>
#include <vector>
using namespace std;
class A
{
	private:
		int a;
		double b;
	public:
		explicit A(int a,double b):a(a),b(b)
		{
			
		}
//		A(const A& x)
//		{
//			cout<<"A(const A& x) called"<<endl;
//		}
//		A(const tuple<int,double>& x)
//		{
//			cout<<"A(const tuple& x) called"<<endl;
//		}
		void show()
		{
			cout<<"a="<<a<<endl<<"b="<<b<<endl;
		}
		
};
int main()
{
	vector<int> h(10,99);
	cout<<h.size()<<endl;
	for(int i=0;i<h.size();++i)
	{
		cout<<h[i]<<" ";
	}
	A a={12,99.3};
	a.show();
	return 0;
}

