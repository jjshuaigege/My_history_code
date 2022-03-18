#include <iostream>
#include <string.h>
using namespace std;
class person
{
	public:
		char* name;
	public:
		person(const char* sname)
		{
			name=new char[strlen(sname)+1]; 
			strcpy(name,sname);
		}
		person(const person& T)
		{
			name=new char[strlen(T.name)+1];
			strcpy(name,T.name);
		}
		virtual ~person()
		{
			delete[] name;
		}
		void printname()
		{
			cout<<"name:"<<name<<endl;
		}
};
int main()
{
	person A("SGZ");
	person B=A;
	A.printname();
	B.printname();
	printf("A.name=%p\n",A.name);
	printf("B.name=%p\n",B.name);
	string zfc1="sgz np";
	string zfc2="520 kl";
	string zfc3=zfc2;
	zfc3.
	cout<<zfc3<<endl;
	return 0;
	
}

