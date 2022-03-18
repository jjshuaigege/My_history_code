#include <iostream>
#include <stdlib.h> 
using namespace std;
void growup(int** a,int n)
{
	int *p=(int*)malloc((n+5)*sizeof(int));
	for(int i=0;i<n;i++)
	{
		p[i]=*a[i];
	}
	free(*a);
	*a=p;
//	int *p=*a;
//	*a=(int*)malloc((n+5)*sizeof(int));
//	for(int i=0;i<n;i++)
//	{
//		*a[i]=p[i];
//	}
//	free(p);
}
int main()
{
	int *a=(int *)malloc(5*sizeof(int));
	int n=0;
	int ii=0;
	cin>>n;
	while(n!=-1)
	{
		a[ii++]=n;
		if(ii%5==0)
		{
//			growup(&a,ii);
			int *p=(int*)malloc((ii+5)*sizeof(int));
			for(int i=0;i<ii;i++)
			{
				p[i]=a[i];
			}
			free(a);
			a=p;
		}
				cin>>n;
	}
	for(int j=0;j<ii;j++)
	{
		cout<<a[j]<<endl;
	}
	return 0;
}

