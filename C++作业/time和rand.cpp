#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	int a[10];
	srand((unsigned int)time(NULL));
	double t=time(NULL);
	for(int i=0;i<10;i++)
	{
		a[i]=rand();
	}
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("t=%f",t);
	return 0;
}

