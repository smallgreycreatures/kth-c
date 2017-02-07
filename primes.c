#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
   int max, factor = 1;
   int i, j, k, l = 0;
   

   scanf("%d", &max);

   int* list = (int*)malloc(sizeof(int) * (max/2));

   for(i = 0; i < max/2; ++i) 
   {
      list[i] = 1;
   }

   int lim = (int)sqrt(max)+1;
   
   /*Sieve of Eratosthenes*/
   for(i = 3; i <= lim; i+=2) {
      
      if(list[i/2] != 0) {
         j = i*i;
         l = i*2;
         for(k =j; k < max; k+=l) {
            list[k/2] = 0;
               //printf("%d, j= %d, i=%d\n",list[j/2].number, j, i );
         }
         factor = 1;
      }
   }

   printf("2 ");

   for(i = 3; i < max; i+=2) {
      if(list[i/2]) {
         printf("%d ",i );
    //     printf("%d ", list[i].number);
      }
   } 
   
   return 0;
} 