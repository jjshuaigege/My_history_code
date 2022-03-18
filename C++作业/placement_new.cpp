#include <iostream>
const int n=10;
using namespace std;
class A
{
	int order;
	int a;
	double b;
	public:
	A(int o,int a,double b):order(o),a(a),b(b)
	{
		cout<<"A(int o,int a,double b):order(o),a(a),b(b)"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
	void print()
	{
		cout<<order<<":"<<"a="<<a<<","<<"b="<<b<<endl;
	}
};
int main()
{
	char* Buf=new char[sizeof(A)*n];
	A* p=reinterpret_cast<A*>(Buf);
	for(int i=0;i<n;++i)
	{
		new(p+i)A(i,8,10.4);
	}
	for(int i=0;i<n;++i)
	{
		p[i].print();
	}
	for(int i=0;i<n;++i)
	{
		p[i].~A();
	}
	A* very=p+3;
	cout<<"look out!"<<endl;
//	very->print();
	A* temp=(A*)(Buf+sizeof(A)*3);
	temp->print();
	delete[] Buf;
//	very->print();
	
	return 0;
}

