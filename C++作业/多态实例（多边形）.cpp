#include <iostream>
#include <math.h>
#include <corecrt_search.h>
using namespace std;
#define pi 3.14159
class Shape
{
public:
	virtual double area() = 0;
	virtual void Print_Info() = 0;
};
class Rectangle:public Shape
{
private:
	double a, b;
public:
	Rectangle(double a, double b) :a(a), b(b)
	{

	}
	virtual double area()
	{
		return a * b;
	}
	virtual void Print_Info()
	{
		cout << "Rectnagle:" << area() << endl;
	}
};
class Triangle:public Shape
{
private:
	double a, b, c;
public:
	Triangle(double a, double b, double c) :a(a), b(b), c(c)
	{

	}

	virtual double area()
	{
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	virtual void Print_Info()
	{
		cout << "Triangle:" << area() << endl;
	}

};
class Circle:public Shape
{
private:
	double raidus;
public:
	Circle(double raidus) :raidus(raidus)
	{

	}
	virtual double area()
	{
		return raidus * raidus * pi;
	}
	virtual void Print_Info()
	{
		cout << "Circle:" << area() << endl;
	}
};
int MyCompare(const void* s1, const void* s2)
{
	double a1, a2;
	Shape** p1;
	Shape** p2;
	p1 = (Shape**)s1;
	p2 = (Shape**)s2;
	a1 = (*p1)->area();
	a2 = (*p2)->area();
	if (a1 < a2)
	{
		return -1;
	}
	else if (a1 > a2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n;
	char c;
	cin >> n;
	Shape* data[100];
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		switch (c)
		{
		case 'R':
			double w, h;
			cin >> w >> h;
			data[i] = new Rectangle(w, h);
			break;
		case 'T':
			double a, b, c;
			cin >> a >> b >> c;
			data[i] = new Triangle(a, b, c);
			break;
		case 'C':
			double  r;
			cin >> r;
			data[i] = new Circle(r);
			break;
		}
	}
	qsort(data, n, sizeof(Shape*), MyCompare);  //MyCompare是一个函数指针	 
	for (int i = 0; i < n; i++)
	{
		data[i]->Print_Info();
	}
	return 0;
}

