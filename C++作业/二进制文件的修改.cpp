#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Student
{
	private:
		//只能使用静态数组 
		char name[20];
		int score;
	public:
		Student()
		{
			
		}
		void set_name(const char* str)
		{
			strcpy(name,str);
		}
		void set_score(const int score)
		{
			this->score=score;
		}
		const char* get_name()
		{
			return name;
		}
		const int get_score()
		{
			return score;
		}
};
int main()
{
	fstream fs("test.dat",ios::in|ios::out|ios::binary);
	//修改文件 
	fs.seekp(2*sizeof(Student),ios::beg);
	fs.write("Mike",sizeof("Mike"));
	//读取文件 
	fs.seekg(0,ios::beg);
	Student s;
	while(fs.read((char*)&s,sizeof(Student)))
	{
		cout<<s.get_name()<<":"<<s.get_score()<<endl;
	}
	fs.close();
	return 0;
}

