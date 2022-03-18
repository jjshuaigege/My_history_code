#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
		friend ostream& operator<<(ostream& o,const Point& x)
		{
			o<<x.x<<","<<x.y;
			return o;
		}
		friend istream& operator>>(istream& i,Point& x)
		{
			i>>x.x>>x.y;
			return i;
		}

}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}

