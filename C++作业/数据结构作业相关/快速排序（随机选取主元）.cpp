#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
template<class T>
void partition(T* a,int s,int e)
{
	if(s>=e-1)
	{
		return;
	}
	else
	{
		static default_random_engine r_e(time(nullptr));
		cout<<"µ÷ÊÔ£º s="<<s<<"\t e-1="<<e-1<<"\t";
		static uniform_int_distribution<int> u(s,e-1);
		int main_ele_loc=u(r_e);
		cout<<"µ÷ÊÔ£º"<<main_ele_loc<<endl;
		T m_ele=a[main_ele_loc];
		swap(a[main_ele_loc],a[s]);
		int i=s,j=e-1;
		while(j>i)
		{
			while(j>i&&a[j]>=m_ele)
			{
				j--;
			}
			swap(a[i],a[j]);
			if(j>i)
			i++;	
			while(j>i&&a[i]<m_ele)
			{
				i++;
			}
			swap(a[i],a[j]);
			if(j>i)
			j--; 
		}
		partition(a,s,i);
		partition(a,i+1,e);	
	}
}
template<class T>
void quick_sort(T* a,int s,int e)
{
	partition(a,s,e);
}
int main()
{
//	double array[]={6.98,4.5,8};
	double array[]={3.2,6.98,4.5,62,77.7,10.6,105.1,89.9};
	quick_sort(array,0,sizeof(array)/sizeof(double));
	for(int i=0;i<sizeof(array)/sizeof(double);++i)
	{
		cout<<array[i]<<"\t";
	}
	cout<<endl;
	return 0;
}

