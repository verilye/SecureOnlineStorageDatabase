#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "value.h"

// break input into chunks
// some input will be symbols and some will be literals

// https://craftinginterpreters.com/chunks-of-bytecode.html#getting-started

typedef enum{
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

typedef struct{
        int count;
        int capacity;
        uint8_t* code;
        int* lines;
        DynamicArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);


#endif