#include <iostream>
using namespace std;
class A
{
	int num;
	public:
	A():num(0)
	{
		
	}
	void set_num(int num)
	{
		this->num=num;
	}
	void do_shopping() const throw()
	{
		if(num==77)
		{
			action();
		}
		else
		{
			cout<<"回调函数没有被调用"<<endl;
		}
	}
	virtual action(void)  const throw()=0;
};
class B:public A
{
	virtual action(void) const throw()
	{
		cout<<"在超市发现了宝藏！"<<endl;
	}
};
class C:public A
{
	virtual action(void) const throw()
	{
		cout<<"买了一大篮子零食和化妆品"<<endl;
	}
};
ostream& tab(ostream& o)
{
	o<<"\t";
	return o;
}
int main()
{
	B b1,b2;
	C c1,c2;
	b1.set_num(88);
	b2.set_num(77);
	c1.set_num(77);
	c2.set_num(99);
	b1.do_shopping();
	b2.do_shopping();
	c1.do_shopping();
	c2.do_shopping();
	cout<<"ce"<<tab<<"shi"<<endl;
	return 0;
}

