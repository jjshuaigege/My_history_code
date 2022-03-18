#include <iostream>
using namespace std;
class Skill
{
	private:
		int value;
	public:
		Skill(int value):value(value)
		{
			cout<<"Skill constructor called"<<endl;	
		}
};
class Bug
{
	private:
		int legs;
		int eyes;
	public:
		Bug(int legs,int eyes):legs(legs),eyes(eyes)
		{
			cout<<"Bug constructor called"<<endl;
		}
};
class Wingbugs:public Bug
{
	private:
		int wings;
		Skill s1;
		Skill s2;
	public:
		Wingbugs(int legs,int eyes,int s1value,int s2value,int wings):wings(wings),s1(s1value),s2(s2value),Bug(legs,eyes)
			{
				cout<<"Wingbugs constructor called"<<endl;
			}
};
int main()
{
	Wingbugs w(8,4,55,56,4);
	return 0;
}

