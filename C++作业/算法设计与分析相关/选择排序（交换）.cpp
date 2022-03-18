#include <iostream>
using namespace std;
template<class T>
void select_sort(T* a,int n)
{
	for(int i=0;i<n;++i)
	{
		int min_ele=i;
		for(int j=i+1;j<n;++j)
		{
			if(a[min_ele]>a[j])
			{
				min_ele=j;
			}
		}
		swap(a[i],a[min_ele]);
	}
}
int main()
{
	int a[20]={5,6,88,45,62,96,102,7,15,33,94,21,85,56,64,21,88,49,55,64};
	select_sort(a,20);
	for(int i=0;i<20;++i)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}

