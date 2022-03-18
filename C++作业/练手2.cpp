#include <iostream>
using namespace std;
class Employee
{
	public:
		int income;
	public: 
		static int total_salary;
		Employee(int income=0):income(income)
		{
			
		}
		void get_payed(int salary)
		{
			income+=salary;
			total_salary+=salary;	
		}
		static int show_total_salary()
		{
			cout<<total_salary<<endl;
			return total_salary;	
		} 
};
int Employee::total_salary=0; 
int main()
{
	Employee e1,e2;
	e1.get_payed(150);
	e2.get_payed(200);
	e1.get_payed(160);
	cout<<e1.income<<" "<<e2.income<<endl;
	Employee::show_total_salary();
	return 0;
}

