#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
	private:
		char p[110]={0};
		char to_print[110]={0};
	public:
		 //将p2的内容颠倒放入p1 
		void myreverse(char* p1,const char* p2)
		{
			int i=0,j=0;
			while(p2[j]!='\0')
			{
				j++;
			}
			j--;
			while(j>=0)
			{
				p1[i++]=p2[j--];		
			}
			p1[i]='\0';
		}
		CHugeInt()
		{
			
		}
		CHugeInt(const char* x)
		{
			strcpy(p,x);
			myreverse(p,x);
//			reverse(p,p+strlen(p));	
		}
		CHugeInt(int x)
		{
			int temp=x;
			int adj=0;
			while(temp!=0)
			{
				p[adj++]=temp%10+'0';
				temp/=10;
			}
			p[adj]='\0';
		}
		CHugeInt operator + (const CHugeInt x)const
		{
			int a1,a2;
			int adj;
			int higher_num=0;
			int this_num=0;
			CHugeInt temp_CHI("0"); 
			for(adj=0;(p[adj]>='0'&&p[adj]<='9')||(x.p[adj]>='0'&&x.p[adj]<='9');adj++)
			{
				if(p[adj]>='0'&&p[adj]<='9')
				{
					a1=p[adj]-'0';
				}
				else
				{
					a1=0;
				}
				if(x.p[adj]>='0'&&x.p[adj]<='9')
				{
					a2=x.p[adj]-'0';
				}
				else
				{
					a2=0;
				}
				this_num=(a1+a2+higher_num)%10;
				temp_CHI.p[adj]=this_num+'0';
				higher_num=(a1+a2+higher_num)/10;	
			}
			if(higher_num!=0)
			{
				temp_CHI.p[adj]=higher_num+'0';
			}
			return temp_CHI;	
		}
		//用于cout 
		operator char*()
		{
//			strcpy(to_print,p);
//			reverse(to_print,to_print+strlen(to_print));
			myreverse(to_print,p);
			return to_print;	
		}
		CHugeInt operator +(int n)
		{
			CHugeInt temp(n);
			return temp+*this;	
		}
		friend CHugeInt operator +(int n,CHugeInt x)
		{
			CHugeInt temp(n);
			return temp+x;	
		}
		CHugeInt& operator=(const CHugeInt& x)
		{
			if(p!=x.p)
			{
				strcpy(p,x.p);
				return *this;
			}
		}
		CHugeInt& operator+=(int n)
		{
			CHugeInt temp(n);
			*this=temp+*this;
			return *this;	
		}
		CHugeInt operator++(int nouse)
		{
			CHugeInt obj=*this;
			CHugeInt temp(1);
			*this=temp+*this;
			return obj;
		}
		CHugeInt& operator++()
		{
//			cout<<"in CHugeInt& operator++() before b="<<*this<<endl;
			CHugeInt temp(1);
			*this=temp+*this;
//			cout<<"in CHugeInt& operator++() b="<<*this<<endl;
			return *this;	
		}
		bool operator< (const CHugeInt x)
		{
			int i=0;
			while(p[i]!=0&&x.p[i]!=0)
			{
				++i;	
			}
			if(p[i]!=0)
			{
				return false;	
			}
			else if(x.p[i]!=0)
			{
				return true;	
			}
			else
			{
				--i;
				while(p[i]==x.p[i])
				{
					--i;	
				}	
				if(p[i]<x.p[i])
				{
					return true;
				}
				else
				{
					return false;
				}
			}	
		}	
};
int  main() 
{ 
//	CHugeInt a("4515315435457564156489789");
//	CHugeInt b("348964564185675641564894564231");
//	cout<<a<<endl;
//	cout<<a+b<<endl;
	char s[210];
	int n;
	char s2[210];
	while (cin >> s >> s2) {
		CHugeInt a(s);
		CHugeInt b(s2);
//
//		cout << a + b << endl;
//		cout << n + a << endl;
//		cout << a + n << endl;
////		cout<<" tiaoshi"<<b<<endl;
//		b += n;
////		cout<<" tiaoshi"<<b<<endl;
//		cout  << ++ b << endl;
//		cout << b++ << endl;
//		cout << b << endl;
		cout<<a+b<<endl;
		cout<<(a<b)<<endl;
	}
	return 0;
}
