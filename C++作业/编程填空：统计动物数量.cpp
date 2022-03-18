#include <iostream>
using namespace std;
class Animal
{
	public:
		static int number;
		Animal()
		{
			number_increase();
		}
		virtual void number_increase()
		{
			number++;
		}
		virtual ~Animal()
		{
			number--;
		}
};
int Animal::number=0;
class Dog:public Animal
{
	public:
		static int number;
		Dog():Animal()
		{
			number_increase();
		}
		virtual void number_increase()
		{
			number++;
		}
		virtual ~Dog()
		{
			number--;
		}
};
int Dog::number=0;
class Cat:public Animal
{
	public:
		static int number;
		Cat():Animal()
		{
			number_increase();
		}
		virtual void number_increase()
		{
			number++;
		}
		virtual ~Cat()
		{
			number--;
		}
};
int Cat::number=0;
void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}

