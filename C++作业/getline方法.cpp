#include <iostream>
using namespace std;
int main()
{
	char* s1=new char[20];
	char* s2=new char[20];
	cin.getline(s1,20,'\\').getline(s2,20,'\\');
//	cin.getline(s2,20,'\\'); 
	cout<<s1<<endl;
	cout<<s2<<endl;
	return 0;
}

