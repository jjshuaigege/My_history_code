#include <iostream>
using namespace std;
int main()
{
	int a[10];
	int cnt=0;
	while(scanf("0x%x",&a[cnt])!=EOF)
	{
		cnt++;
	}
	for(int i=0;i<cnt;i++)
	printf("%d\n",a[i]);
	return 0;
}

