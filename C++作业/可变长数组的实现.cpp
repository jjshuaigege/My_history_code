#include <iostream>
using namespace std;
class CArray
{
private:
	int l;
	int* a;
public:
	CArray() :a(NULL), l(0)
	{

	}
	~CArray()
	{
		if(a!=NULL)
		{
			delete[] a;
		}
	}
	CArray& operator=(const CArray x)
	{
		delete[] a;
		if(x.a==NULL)
		{
			
			a=NULL;
			l=0;
		}
		else
		{
			a = new int[x.l];
			for (int i = 0; i < x.l; i++)
			{
				a[i] = x.a[i];
			}
			l=x.l;
		}
		return *this;
	}
	int& operator[](int i)    // 为什么是int&？考虑n=a[i]和a[i]=4 
	{
		return a[i];
	}
	CArray(const CArray& x)
	{
		if(x.a==NULL)
		{
			a=NULL;
			l=0;
		}
		else
		{
			a = new int[x.l];
			l=x.l;
			for (int i = 0; i < x.l; i++)
			{
				a[i] = x.a[i];
			}
		}
	}
	void push_back(int k)
	{
		int* p = a;
		a = new int[l + 1];
		int i;
		for (i = 0; i < l; i++)
		{
			a[i] = p[i];
		}
		a[i] = k;
		l++;
		delete[] p;
	}
	int length() const
	{
		return l;
	}

};
int main()
{
	CArray a;
	for (int i = 0; i < 5; ++i)
	{
		a.push_back(i);
	}
	CArray a2, a3;
	a2 = a;
	for (int i = 0; i < a.length(); ++i)
	{
		cout << a2[i] << " ";
	}
	a2 = a3;
	for (int i = 0; i < a2.length(); ++i)
	{
		cout << a2[i] << " ";
	}
	cout << endl;
	a[3]=100;
	CArray a4(a);
	for(int i=0;i<a4.length();++i)
	{
		cout<<a4[i]<<" ";
	}
	return 0;
}

