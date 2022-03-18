#include <iostream>
using namespace std;
int main()
{
	int a;
	char* Buf=new char[100];
//	(cin>>a).ignore(1).getline(Buf,90);
	cin>>a;
	cin.ignore(1);
	cin.getline(Buf,90);
	cout<<a<<endl<<Buf; 
	return 0;
}

