#include <stdio.h>
int main()
{
	enum color{red,blue,yellow,green};
	int i=green;
	printf("%d\n",i);
	enum color j=yellow;
	printf("%d\n",j);
	j=12;
	printf("%d\n",j);
	return 0;
}

