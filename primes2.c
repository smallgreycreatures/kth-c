#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
   int max, factor = 1;
   int i, j, k = 0;
   Number *list;

   scanf("%d", &max);

   list = malloc(sizeof(Number) * max/2);

   for(i = 1; i < max/2; i+=2) {
      
      list[i].is_prime = 1;
      list[i].number = i;  
   }

   int limit = 1+(int)sqrt((double)max);

   for (int divisor = 3; divisor <=limit; divisor+=2)
   {
      if (list[divisor/2].is_prime==0 )
         continue;
      int index = divisor*divisor;
      int doublediv = divisor*2;

      for(;index<max; index+=doublediv)
      {
         list[index/2].is_prime = 0;
      }
   }
   
   printf("2 ");

   for(i = 3; i < max; i+=2) {
      if(list[i/2].is_prime) {
    
         printf("%d ", i);
      }
   } 

   return 0;
} 