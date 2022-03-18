#include <stdio.h>
int main()
{
	int x=78;
	const int * p=&x;
	*p=88;
	return 0;
}

