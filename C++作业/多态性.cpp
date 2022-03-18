#include <iostream>
using namespace std;
class shape
{
	protected:
		int x,y;    //���ĵ�ĺ�������
	public:
		shape():x(0),y(0){}
		virtual ~shape(){}
		void move(int xs,int ys){x+=xs;y+=ys;}
		virtual void draw(){cout<<"������һ��shapeͼ��"<<endl;}
};
class ellipse:public shape
{
	public:
		virtual ~ellipse(){}
		virtual void draw(){cout<<"������һ��ellipseͼ��"<<endl;}
};
class circle:public ellipse
{
	public:
		virtual ~circle(){}
		virtual void draw(){cout<<"������һ��circleͼ��"<<endl;}
};
void draw(shape* p)  //p���ж�̬�� 
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

