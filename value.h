#ifndef VALUE_H
#define VALUE_H

#include "common.h"

typedef double Value;

typedef struct{
    int count;
    int capacity;
    Value * values;
} DynamicArray;

void initDynamicArray(DynamicArray* array);
void writeDynamicArray(DynamicArray* array, Value value);
void freeDynamicArray(DynamicArray* array);
void printValue(Value value);

#endif