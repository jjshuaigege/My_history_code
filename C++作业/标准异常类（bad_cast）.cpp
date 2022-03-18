#include <iostream>
#include <stdexcept>
using namespace std;
class A
{
protected:
	int a;
	double b;
public:
	virtual void print()
	{
		cout << a << " " << b << endl;
	}
	virtual ~A()
	{

	}
};
class B :public A
{
	double c;
public:
	virtual void print()
	{
		cout << a << " " << b << " " << c << endl;
	}
};
int main()
{
	A a;
	B b;
	A& r1 = a;
	try
	{
		B& r2 = dynamic_cast<B&>(r1);
		cout << "end" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}

