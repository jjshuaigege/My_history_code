#include <iostream>
using namespace std;
class Rectangle
{
private:
	int x; int y;
public:
	Rectangle(const Rectangle& x)
	{
		this->x = x.x;
		this->y = x.y;
		cout << "Rectangle produced1" << endl;
	}
	Rectangle(int x, int y) :x(x), y(y)
	{
		cout << "Rectangle produced2" << endl;
	}
	const int &Get_x() const throw()
	{
		return x;
	}
	const int &Get_y() const throw()
	{
		return y;
	}
};
int main()
{
	Rectangle r(4,8);
	cout << r.Get_x() << endl << r.Get_y() << endl;
	return 0;
}
