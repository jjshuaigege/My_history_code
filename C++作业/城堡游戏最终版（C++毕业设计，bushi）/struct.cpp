#include <iostream>
using namespace std;
int main()
{
	struct data
	{
		int year;
		int month;
		int day;
		data(int year,int month,int day):year(year),month(month),day(day)
		{
			
		}
		void show()
		{
			cout<<year<<"-"<<month<<"-"<<day<<endl;
		}
	};
	class time:public data
	{
		private:
			int hour;
		public:
			time(int year,int month,int day,int hour):data(year,month,day),hour(hour)
			{
				
			}
			void show_hour()
			{
				cout<<hour<<endl;
			}
	};
	class data1
	{
		public:
		double year;
		int month;
		int day;
		data1()=delete;
		~data1()
		{
			cout<<"~data1()"<<endl;
		}
		show()
		{
			cout<<year<<"-"<<month<<"-"<<day<<endl;
		}
	};
	data h(2021,11,16);
	h.show();
	time now(2021,11,16,20);
	now.show_hour();
	data1 example={2021.9,11,16}; 
	example={2022.10,12,17};
	
	return 0;
}

