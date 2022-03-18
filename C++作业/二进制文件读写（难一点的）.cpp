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
	ifstream ifs;
	ofstream ofs;
	Student s;
	//写文件
//	ofs.open("test.dat",ios::out|ios::binary);
//	if(!ofs)
//	{
//		cout<<"write file failed!"<<endl;
//	}
//	else
//	{
//		int score;
//		char* Buf=new char[20];
//		while(cin>>Buf&&cin>>score)
//		{
//			s.set_score(score);
//			s.set_name(Buf);
//			ofs.write((const char*)&s,sizeof(Student));
//		}
//	}
//	ofs.close();
	//读文件 
	ifs.open("..\\mydata.dat",ios::in|ios::binary);
	if(!ifs)
	{
		cout<<"read file failed!"<<endl;
	}
	else
	{
		while(ifs.read((char*)&s,sizeof(Student)))
		{
			cout<<s.get_name()<<":"<<s.get_score()<<endl;
		}
	}
	ifs.close();
	
	return 0;
}

