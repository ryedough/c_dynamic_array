#include <dynamic_array.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define INIT_CAP 2

struct header{
    size_t capacity;
    size_t length;
};

int * daInit() {
   Header *h = malloc(sizeof(*h) + (sizeof(int) * INIT_CAP));
   h->capacity=INIT_CAP;
   h->length=0;
   printf("header : %p, sizeof : %td\n", h, sizeof(*h));
   printf("int : %p\n", (int*) (h+1));
   return (int*) (h+1);
}

void daPush(int** arr, int value){
    Header *h = (Header *)(*arr)-1;
    if(h->capacity < h->length + 1) {
        size_t new_cap = h->capacity * 2;
        Header *new_h = realloc(h, sizeof(*h) + (sizeof(int) * new_cap));
        printf("%p\n", new_h);
        if(!new_h){
            fprintf(stderr,"%s","cant reallocate array\n");
            exit(1);
        }
        h = new_h;
        *arr = (int *)(h+1);
        h->capacity = new_cap;
        printf("RESIZING YO SHII \n");
    }
    (*arr)[h->length] = value;

    h->length += 1;
}

int daPop(int* arr){
    Header *h = (Header*) arr-1;
    if(!h->length){
        return 0;
    }
    h->length -= 1;
    return arr[h->length];
}

size_t daLen(int* arr){
    Header *h = (Header *) arr-1;
    return h->length;
}
