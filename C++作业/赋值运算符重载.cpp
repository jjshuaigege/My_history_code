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
		//��д���ƹ��캯��,��ֹstrָ��ͬһƬ�ռ� 
		String(const String& s)
		{
			str=new char[strlen(s.Get_str())+1];
			strcpy(str,s.Get_str());	
		} 
		~String()
		{
			delete[] str;
		}
		String& operator=(const char* new_str) //a=b��Ч��a.operator=(b) 
		{
			delete[] str;
			str=new char[strlen(new_str)+1];
			strcpy(str,new_str);
			return *this;	
		}
		String& operator=(const String& s)    //Ϊʲô����ֵ������void��a=b=c;Ϊʲô����ֵ������String��(a=b)=c 
		{
			cout<<"String& operator=(const String s) called"<<endl;
			if(this!=&s)   //��ֹs=s��ֵ���
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
//	String s2="fjdsf";        //�˴��ǳ�ʼ�������Ǹ�ֵ��� 
	s1.print();
	s2="123�Ұ���";
	s2=s1;
	s2="456��һ��";
	s1.print();
	fushu f={4,5};
	cout<<f.real<<endl<<f.image<<endl;
	cout<<strlen(NULL)<<endl;
	
	return 0;
}

