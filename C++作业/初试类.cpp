#include <iostream>
using namespace std;
class Rectangle{
	public:
		Rectangle()
		{
			
		}
		Rectangle(int x,int y)
		{
			this->x=x;
			this->y=y;
		}
		~Rectangle()
		{
			cout<<" ±»Îö¹¹À²£¡"<<endl;
		}
		int Area()
		{
			return x*y;
		}
		int Perimeter()
		{
			return 2*(x+y);
		}
		void Init(int x,int y)
		{
			this->x=x;
			this->y=y;
		}
		int Getx();
		int Gety();
	private:
		int x;
		int y;
		
};
int Rectangle::Getx()
		{
			return x;
		}
int Rectangle::Gety()
		{
			return y;
		}
int main()
{
	{
		Rectangle r;
		r.Init(3,4);
		cout<<"r.Perimeter():"<<r.Perimeter()<<endl;
		cout<<"r.Area():"<<r.Area()<<endl;
	}
	Rectangle r1(5,7);
	cout<<"r1.Perimeter():"<<r1.Perimeter()<<endl;
	cout<<"r1.Area():"<<r1.Area()<<endl;
	Rectangle& r1r=r1;
	r1r.Init(6,8);
	cout<<"r1.Perimeter():"<<r1.Perimeter()<<endl;
	cout<<"r1.Getx():"<<r1.Getx()<<endl;
	cout<<"r1.Gety():"<<r1.Gety()<<endl;
	
	return 0;
}

