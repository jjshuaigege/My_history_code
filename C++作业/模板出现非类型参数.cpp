#include <iostream>
using namespace std;
//模板出现非类型参数 
template <typename T,int size>
class array
{
	private:
		T a[size];
	public:
		array()
		{
			for(int i=1;i<=size;++i)
			{
				a[i-1]=i;
			}
		}
		void print()
		{
			for(int i=0;i<size;i++)
			{
				cout<<a[i]<<endl;
			}	
		}	
};
int main()
{
	array<double,40> a1;
	array<double,50> a2;
	//a1和a2是不同的类！ 
	a1.print();
	a2.print();
	return 0;
}

