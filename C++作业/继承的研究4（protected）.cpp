#include <iostream>
using namespace std;
class Father
{
	private:
		int private_N;
	public:
		int public_N;
	protected:
		int protected_N;
	Father(int private_N,int public_N,int protected_N):private_N(private_N),public_N(public_N),protected_N(protected_N)
	{
		
	}
		
	
};
class Son:public Father
{
	public:
		Son(int private_N,int public_N,int protected_N):Father(private_N,public_N,protected_N)
		{
			
		}
		void func()
		{
			
			Son s(45,55,65);
			s.protected_N=1;
			s.show_protected();
			show_protected();
			
		}
		void show_protected()
		{
			cout<<protected_N<<endl;
		}
};
int main()
{
	Son s1(55,60,65);
	s1.func();
	return 0;
}

