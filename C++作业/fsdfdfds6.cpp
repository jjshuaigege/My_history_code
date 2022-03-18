#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
   int i, n;
   time_t t;
   
   n = 5;
   
   /* ????????? */
   srand(time(&t));
 
   /* ?? 0 ? 50 ??? 5 ???? */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   
  return(0);
}

