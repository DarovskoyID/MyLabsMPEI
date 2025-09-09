//
// Created by BottomWeb on 08.09.2025.
//

#include "dynamicArray.h"

void initArray(DynamicArray *arr, int initialCapacity) {
    arr->data = (int*)malloc(initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
}

void pushBack(DynamicArray *arr, int value) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size] = value;
    arr->size++;
}

void popBack(DynamicArray *arr) {
    if (arr->size > 0) {
        arr->size--;
    }
}

int getAt(DynamicArray *arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->data[index];
    }

}

void setAt(DynamicArray *arr, int index, int value) {
    if (index >= 0 && index < arr->size) {
        arr->data[index] = value;
    }

}

void freeArray(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}
