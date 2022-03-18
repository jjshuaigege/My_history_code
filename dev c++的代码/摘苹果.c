#include <stdio.h>
int main()
{
	int n,height;
	unsigned int cnt=-1;
	const int chair=30;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d ",&a[i]);
	}
	scanf("%d",&height);
	for(int i=0;i<n;i++)
	{
		if(a[i]<=height+chair)
		cnt++;
	}
	printf("%d\n",cnt);
	if(cnt==n)
	printf("Yes");
	else
	printf("No");
    return 0;
}

