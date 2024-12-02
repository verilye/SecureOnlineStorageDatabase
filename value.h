#ifndef VALUE_H
#define VALUE_H

#include "common.h"

typedef struct Obj Obj;

typedef enum{
    VAL_BOOL,
    VAL_NIL,
    VAL_STRING,
    VAL_NUMBER,
    VAL_OBJ
    VAL_FILE
} ValueType;

typedef struct{
    ValueType type;
    union{
        bool boolean;
        double number;
        Obj* obj;
        char* string;
        char* file;
    } as;
} Value;

#define IS_BOOL(value)      ((value).type ==  VAL_BOOL)
#define IS_NIL(value)      ((value).type ==  VAL_NIL)
#define IS_NUMBER(value)      ((value).type ==  VAL_NUMBER)
#define IS_OBJ(value)     ((value).type == VAL_OBJ)

// Converts the values to appropriate union valye type
#define AS_BOOL(value)   ((value).as.boolean)
#define AS_NUMBER(value) ((value).as.number) 
#define AS_OBJ(value)     ((value).as.obj)

// Macros for handling all the different types of value
#define BOOL_VAL(value)   ((Value){VAL_BOOL, {.boolean = value}})
#define NIL_VAL           ((Value){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})
#define OBJ_VAL(object)   ((Value){VAL_OBJ, {.obj = (Obj*)object}})

typedef struct{
    int count;
    int capacity;
    Value * values;
} DynamicArray;

bool valuesEqual(Value a, Value b);
void initDynamicArray(DynamicArray* array);
void writeDynamicArray(DynamicArray* array, Value value);
void freeDynamicArray(DynamicArray* array);
void printValue(Value value);

#endif