#include <dynamic_array.h>
#include <stdio.h>
#include <stdlib.h>

#define Assert(x, y, msg) do{\
    if((x) != (y)){\
        fprintf(stderr, "Fail at : %s\n", (msg));\
        exit(1);\
    }\
    printf("Success : %s\n", (msg));\
}while(0)

int main(){
   int* darr = NULL;

   for(int i=0; i<5; i++){
       da_push(darr, i+1);
   }
   Assert(da_len(darr), 5, "Pushing 5 elements");
   for(int i=da_len(darr); i>0; i--){
       int *pop;
       da_pop(darr, pop);
       Assert(*pop, i, "Pop test");
   }
   Assert(da_len(darr), 0, "Popping all elements");
   for(int i=0; i<5; i++){
       int *pop;
       da_pop(darr, pop);
       Assert(pop, NULL, "Popping empty array");
   }
   for(int i=30; i <40; i++){
       da_push(darr, i);
   }
   Assert(darr[da_len(darr)-1], 39, "Final push last element");
   Assert(da_len(darr), 10, "Final push length result");
   da_free(darr);
   Assert(darr, NULL, "after da_free call should be null");
}
