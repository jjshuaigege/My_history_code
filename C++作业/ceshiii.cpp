#include <stdio.h>
int main()
{
	enum color{red,blue,yellow,green};
	int i=green;
	printf("%d",i);
	color j=yellow;
	printf("%d",j);
	j=12;
	printf("%d",j);
	return 0;
}

