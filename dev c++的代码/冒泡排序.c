//9:11
#include <stdio.h>
void swap(int *a,int *b);
void bubblesort(int A[],int num);
void print(int A[],int pause,int num);
int main()
{
	int num;
	scanf("%d",&num);
	int A[num];
	for(int i=0;i<num;i++)
	{
		scanf("%d",&A[i]);
	}
	bubblesort(A,num);
    return 0;
}
void bubblesort(int A[],int num)
{
	int i,j,k;
	printf("Source:\n");
	print(A,num,num);
	printf("Bubble Sort:\n");
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1-i;j++)
		if(A[j]>A[j+1])
		{
			swap(&A[j],&A[j+1]);
		}
		print(A,num-i-1,num);
	}
	printf("Result\n");
	print(A,num,num);
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int A[],int pause,int num)
{
	printf("(");
	int j;
	for(j=0;j<pause;j++)
	{
	printf("%d",A[j]);
	if(j<pause-1)
	printf(" ");
	}
	printf(")");
	if(j<num)
	printf(" ");
	for(;j<num;j++){
	printf("%d",A[j]);
	if(j<num-1)
	printf(" ");
	}
	printf("\n");
}

