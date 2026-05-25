#include <dynamic_array.h>
#include <stdio.h>

int main(){
   int* darr = daInit();

   for(int i=0; i<20; i++){
       daPush(&darr, i);
   }
   for(int i=0; i<daLen(darr); i++){
       printf("%d,", darr[i]);
   }
   printf("len : %td\n", daLen(darr));
   size_t half_len = daLen(darr)/2;
   for(int i=0; i < half_len; i++){
       int p = daPop(darr);
       printf("poppin : %d, i : %d \n", p, i);
   }
   printf("len : %td\n", daLen(darr));
   for(int i=30; i <40; i++){
       daPush(&darr, i);
   }
   for(int i=0; i<daLen(darr); i++){
       printf("%d,", darr[i]);
   }
   printf("\n");
   printf("final length : %td", daLen(darr));
}
