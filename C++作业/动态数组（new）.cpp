#include <iostream>
using namespace std;
void growup(int**a,int n)
{
	int* p=new int[n+5];
	for(int i=0;i<n;i++)
	{
		p[i]=(*a)[i];
	}
	delete [] *a;
	*a=p;
}
int main()
{
	int* a=new int[5];
	int n;
	int index=0;
	cin>>n;
	while(n!=-1)
	{
		a[index++]=n;
		if(index%5==0)
		{
			growup(&a,index);
		}
		cin>>n;
	}
	for(int i=0;i<index;i++)
	{
		cout<<a[i]<<endl;
	}
	delete [] a;
	return 0;
}

