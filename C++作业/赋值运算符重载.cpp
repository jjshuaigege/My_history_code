#include <iostream>
#include <string.h>
using namespace std;
class String
{
	private:
		char* str;
	public:
		String():str(new char[1])
		{
			*str='0';	
		}
		//重写复制构造函数,防止str指向同一片空间 
		String(const String& s)
		{
			str=new char[strlen(s.Get_str())+1];
			strcpy(str,s.Get_str());	
		} 
		~String()
		{
			delete[] str;
		}
		String& operator=(const char* new_str) //a=b等效于a.operator=(b) 
		{
			delete[] str;
			str=new char[strlen(new_str)+1];
			strcpy(str,new_str);
			return *this;	
		}
		String& operator=(const String& s)    //为什么返回值不能是void？a=b=c;为什么返回值不能是String？(a=b)=c 
		{
			cout<<"String& operator=(const String s) called"<<endl;
			if(this!=&s)   //防止s=s赋值语句
			{ 
				delete[] str;
				str=new char[strlen(s.Get_str())+1];
				strcpy(str,s.Get_str());
			}
			return *this;
		}
		void print()
		{
			cout<<str<<endl;	
		}
		const char* Get_str() const
		{
			return str;	
		}	
};
class fushu
{
	public:
		int real;
		int image;
	public:
		fushu(int real,int image):real(real),image(image)
		{
			
		}
};
int main()
{
	String s1,s2;
	s1="hello,motherfucker";
//	String s2="fjdsf";        //此处是初始化语句而非赋值语句 
	s1.print();
	s2="123我爱你";
	s2=s1;
	s2="456在一起";
	s1.print();
	fushu f={4,5};
	cout<<f.real<<endl<<f.image<<endl;
	cout<<strlen(NULL)<<endl;
	
	return 0;
}

