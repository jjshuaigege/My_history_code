#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Rectangle
{
	int w;
	int h;
	public:
	Rectangle(int w,int h):w(w),h(h)
	{
		
	}
	bool operator <(Rectangle x)
	{
		return w*h<x.w*x.h;
	}
	bool operator >(Rectangle x)
	{
		return w*h>x.w*x.h;
	}
	bool operator ==(Rectangle x)
	{
		return w*h==x.w*x.h;
	}
	void print()
	{
		cout<<w*h<<endl;
	}
};
bool mycompare(Rectangle x1,Rectangle x2)
{
	return x1<x2;
}
int main()
{
	vector<Rectangle> a;
	//在尾部增加或删除一个元素 （push_back,pop_back） 
	a.push_back(Rectangle(12,13));
	a.push_back(Rectangle(9,15));
	a.push_back(Rectangle(20,20));
	a.push_back(Rectangle(11,11));
	sort(a.begin(),a.end(),mycompare);
	cout<<"------"<<endl;
	for(int i=0;i<a.size();i++)
	{
		a.at(i).print();
	}
	cout<<"------"<<endl;
	//插入一个元素 
	a.insert(a.begin()+2,Rectangle(60,60));
	cout<<"------"<<endl;
	for(int i=0;i<a.size();i++)
	{
		a.at(i).print();
	}
	cout<<"------"<<endl;
	//删除一个元素(或一个区间)
	a.erase(a.begin()+3);
	cout<<"------"<<endl;
	for(int i=0;i<a.size();i++)
	{
		a.at(i).print();
	}
	cout<<"------"<<endl;
	return 0;
}

