#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student 
{
	private:
		char* name;
		int age;
		int id;      //??
		char c;      //??????,??","
		double grade1;
		double grade2;
		double grade3;
		double grade4;
		double average_grade;
	public:
		Student() :name(new char[40]),age(0),id(0), grade1(0), grade2(0), grade3(0), grade4(0), average_grade(0)
		{

		}
		void input()
		{
			cin.getline(name, 40, ',');
			cin >> age >> c >> id >> c >> grade1 >> c >> grade2 >> c >> grade3 >> c >> grade4;

		}
		void calculate()
		{
			average_grade = (grade1 + grade2 + grade3 + grade4) / 4;
		}
		void output() const
		{
			cout << name << "," << age << "," << id << "," << average_grade << endl;
		}
		 
};

int main() {
	Student student;        // ??????
	student.input();        // ????
	student.calculate();    // ??????
	student.output();       // ????
}
