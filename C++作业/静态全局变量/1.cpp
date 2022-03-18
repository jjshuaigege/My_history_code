#include <iostream>
#include "1.h"
static int i;
int j;
static inline g()
{
j=40+i;	
}
void f()
{
i=20;
g();
}
