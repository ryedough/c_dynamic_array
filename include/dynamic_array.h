#pragma once

#include <stddef.h>
typedef struct header Header;
int* daInit();
void daPush(int**, int);
int daPop(int*);
size_t daLen(int*);
