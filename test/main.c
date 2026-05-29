#include <dynamic_array.h>
#include <stdio.h>
#include <stdlib.h>

#define Assert(x, msg) do{\
    if(!(x)){\
        fprintf(stderr, "Fail at : %s\n", (msg));\
        exit(1);\
    }\
    printf("Success : %s\n", (msg));\
}while(0)

void basic(){
   int* darr = NULL;

   for(int i=0; i<5; i++){
       da_push(darr, i+1);
   }
   Assert(da_len(darr) == 5, "Pushing 5 elements");
   for(int i=da_len(darr); i>0; i--){
       int *pop;
       da_pop(darr, pop);
       Assert(*pop == i, "Pop test");
   }
   Assert(da_len(darr) == 0, "Popping all elements");
   for(int i=0; i<5; i++){
       int *pop;
       da_pop(darr, pop);
       Assert(pop == NULL, "Popping empty array");
   }
   for(int i=30; i <40; i++){
       da_push(darr, i);
   }
   Assert(darr[da_len(darr)-1]== 39, "Final push last element");
   Assert(da_len(darr)== 10, "Final push length result");
   da_free(darr);
   Assert(darr == NULL, "after da_free call should be null");
}

void custom_capacity_array(){
    float *darr = NULL;
    da_create(darr, ((float[]){0.1f, 0.2, 0.3}), 3, 8);
    Assert(da_len(darr) == 3, "da_create array");
    for(int i=0; i<10; i++){
        da_push(darr, i);
    }
    Assert(da_len(darr) == 13 && darr[da_len(darr)-1] == 9, "push to da_create'd array");
    for(int i=0; i<50; i++){
        float* res;
        da_pop(darr, res);
    }
    Assert(da_len(darr) == 0, "pop till empty");
    for(int i=0; i<10; i++){
        da_push(darr, i);
    }
    Assert(da_len(darr) == 10 && darr[da_len(darr)-1] == 9, "push to da_pop'ed array");
    da_free(darr);
    Assert(darr == NULL, "after da_free call should be null");
}

int main(){
    basic();
    custom_capacity_array();
}

