//
// Created by BottomWeb on 08.09.2025.
//

#ifndef UNTITLED3_DYNAMICARRAY_H
#define UNTITLED3_DYNAMICARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *arr, int initialCapacity);

void pushBack(DynamicArray *arr, int value);

void popBack(DynamicArray *arr);

int getAt(DynamicArray *arr, int index);

void freeArray(DynamicArray *arr);

#endif //UNTITLED3_DYNAMICARRAY_H
