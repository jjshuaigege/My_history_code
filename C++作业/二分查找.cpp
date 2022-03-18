#include <iostream>
using namespace std;
int binarysearch(int* a,int low,int high,int x)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
		{
			return mid;
		}
		else if(a[mid]<x)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return -1; 
}
int main()
{
	int a[10]={0,1,4,5,8,9,176,944,1000,10001};
	printf("%d",binarysearch(a,0,9,176));
	return 0;
}

