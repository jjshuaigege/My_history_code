#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	MyString (const MyString& x)
	{
		if(p!=x.p)
		{
			p=new char[strlen(x.p)+1];
			strcpy(p,x.p);
		}
	}
	~MyString() { if(p) delete [] p; }
	void Copy(char* x)
	{
		if(x!=p)
		{
			if(p)
			{
				delete[] p;
			}
			p=new char[strlen(x)+1];
			strcpy(p,x);
		}
	}
	MyString& operator = (MyString& x)
	{
		if(p!=x.p)
		{
			if(p)
			{
				delete[] p;
			}
			p=new char[strlen(x.p)+1];
			strcpy(p,x.p);
		}
		return *this;
	}
	MyString& operator = (const char* x)
	{
		if(p!=x)
		{
			if(p)
			{
				delete[] p;
			}
			p=new char[strlen(x)+1];
			strcpy(p,x);
		}
		return *this;
	}
	operator char*()
	{
		return p;
	}
//	friend ostream& operator<<(ostream& o,MyString x);
	
};
//ostream& operator<<(ostream& o,MyString x)
//{
//	o<<x.p;
//}
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
//		MyString s1(w1);
//		MyString s2=s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}

