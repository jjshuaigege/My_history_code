#include <iostream>
using namespace std;
class Mergesort
{
	public:
	template <class T>
	void mergesort(T* a,int s,int e)   //左闭右开 
	{
		if(s==e-1)
		{
			return;
		}
		else
		{
			int mid=(s+e-1)/2;
			mergesort(a,s,mid+1);
			mergesort(a,mid+1,e);      //至此，该序列左右两部分已经有序
			T* b=new T[e];
			for(int i=s;i!=e;++i)
			{
				b[i]=a[i];
			}
			int i=s,j=mid+1,k=s;
			while(i!=mid+1&&j!=e)
			{
				if(b[i]<=b[j])
				{
					a[k++]=b[i++];
				}
				else
				{
					a[k++]=b[j++];
				}
			}
			while(i!=mid+1)
			{
				a[k++]=b[i++];
			}
			while(j!=e)
			{
				a[k++]=b[j++];
			}
			delete[] b; 
			return;
 		}
	}
};
int main()
{
	double array[]={68,45,12,53,64,89,101,201,56,42};
	Mergesort way;
	way.mergesort(array,0,sizeof(array)/sizeof(double));
	for(int i=0;i<sizeof(array)/sizeof(double);++i)
	cout<<array[i]<<"\t";
	cout<<endl;
	return 0;
}

