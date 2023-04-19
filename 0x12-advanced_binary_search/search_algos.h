#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <stdlib.h>

int recursive_search(int *array, size_t first, size_t last, int value);
void array_print(int *array, int start, int end);
int advanced_binary(int *array, size_t size, int value);

#endif
