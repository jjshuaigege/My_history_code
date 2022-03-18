#include <iostream>
using namespace std;
class person
{
	public:
		person(const char*n,int ge);
		~person();
		void print();
	private: 
		const char* name;
		int gender;      //1代表男，0代表女 
};
class currency
{
	public:
		currency(int a,int gr);
		~currency();
		void print();
	private:
		int age;
		int grade;
};
class student
{
	public:
		student(const char* n,int ge,int a,int gr);
		~student();
		void print();
	private:
		person m_person;
		currency m_currency;
};
student::student(const char* n,int ge,int a,int gr):m_currency(a,gr),m_person(n,ge){cout<<"student::student"<<endl;};

person::person(const char*n,int ge):name(n),gender(ge){cout<<"person::person"<<endl;};

currency::currency(int a,int gr):age(a),grade(gr){cout<<"currency::currency"<<endl;};
void student::print()
{
	m_person.print();
	m_currency.print();
}

void person::print()
{
	cout<<"name:"<<name<<endl;
	cout<<"gender:"<<gender<<endl;
}

void currency::print()
{
	cout<<"age:"<<age<<endl;
	cout<<"grade:"<<grade<<endl;
}

student::~student()
{
	cout<<"student end"<<endl;
//	m_person.~person();
//	m_currency.~currency();
}
person::~person()
{
	cout<<"at last name:"<<name<<endl;
	cout<<"at last gender:"<<gender<<endl;
}
currency::~currency()
{
	cout<<"at last age:"<<age<<endl;
	cout<<"at last grade:"<<grade<<endl;
}
int main()
{
	const char* new_name="SGZ";
	student s(new_name,1,23,388);
	s.print();
	return 0;
}

