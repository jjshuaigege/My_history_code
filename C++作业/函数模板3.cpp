#include <iostream>
using namespace std;
template <class T>
T find_max_element(T* a,int size)
{
	T max=a[0];
	for(int i=1;i<size;++i)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	cout<<"sizeof(a)="<<sizeof(a)<<endl;
	return max;
}
int main()
{
	double array[]={3.1,99.3,25.6,100.8,9.93,88.8,102.2,10.22,55.66};
	cout<<find_max_element(array,sizeof(array)/sizeof(double))<<endl;
	return 0;
}

