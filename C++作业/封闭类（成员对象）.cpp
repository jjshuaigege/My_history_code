#include <iostream>
using namespace std;
class Tyre
{
	private:
		int radius;
		int width;
	public:
	Tyre():radius(78),width(78)
	{
		cout<<"上当了"<<endl;
	}
	Tyre(int r,int w):radius(r),width(w)
	{
		cout<<"执行有参构造函数"<<endl;
	}
	~Tyre()
	{
		cout<<"执行析构函数"<<endl;
	}
	void print_r_w()
	{
		cout<<"excuting print_r_w()"<<endl;
		cout<<"radius="<<radius<<endl;
		cout<<"width="<<width<<endl;
	}
};
class Engine
{
	public:
		Engine()
		{
			cout<<"执行Engine的空参构造函数"<<endl;
		}
		~Engine()
		{
			cout<<"执行Engine的析构函数"<<endl;
		}
	
};
class Car
{
	private:
		int price;
		Tyre tyre;     //此处是声明，而非定义 
		Engine engine;
	public:
		Car(int p,int r,int w):price(p),tyre(r,w),engine()
		{
			cout<<"car_constructor called"<<endl; 

		}
		~Car()
		{
			cout<<"car_destructor called"<<endl;
		}
		void print_price()
		{
			cout<<"excuting print_price()"<<endl;
			cout<<"price="<<price<<endl;
		}
		Tyre& get_tyre()
		{
			return tyre;
		}
		
};
int main()
{
	Car car1(300000,25,10);
	car1.print_price();
	car1.get_tyre().print_r_w();
//	Tyre tyre1(30,20);
//	Tyre* p=&tyre1;
//	p=new Tyre(30,20);
	return 0;
}

