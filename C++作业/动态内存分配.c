#include <stdio.h>
#include <stdlib.h>
void growup(int** a,int n)
{
	int *p=(int*)malloc((n+5)*sizeof(int));
	for(int i=0;i<n;i++)
	{
		p[i]=(*a)[i];
	}
	free(*a);
	*a=p;
}

int main()
{
	int *a=(int *)malloc(5*sizeof(int));
	int n=0;
	int ii=0;
	scanf("%d",&n);
	while(n!=-1)
	{
		a[ii++]=n;
		if(ii%5==0)
		{
			growup(&a,ii);
		}
				scanf("%d",&n);
	}
	for(int j=0;j<ii;j++)
	{
		printf("%d\n",a[j]);
	}
	free(a);
	return 0;
}

