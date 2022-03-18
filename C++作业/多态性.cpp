#include <iostream>
using namespace std;
class shape
{
	protected:
		int x,y;    //中心点的横纵坐标
	public:
		shape():x(0),y(0){}
		virtual ~shape(){}
		void move(int xs,int ys){x+=xs;y+=ys;}
		virtual void draw(){cout<<"画出了一个shape图形"<<endl;}
};
class ellipse:public shape
{
	public:
		virtual ~ellipse(){}
		virtual void draw(){cout<<"画出了一个ellipse图形"<<endl;}
};
class circle:public ellipse
{
	public:
		virtual ~circle(){}
		virtual void draw(){cout<<"画出了一个circle图形"<<endl;}
};
void draw(shape* p)  //p具有多态性 
{
	p->draw();
}
int main()
{
	shape s;
	ellipse e;
	circle c;
	draw(&e);
	draw(&s);
	draw(&c);
	return 0;
}

