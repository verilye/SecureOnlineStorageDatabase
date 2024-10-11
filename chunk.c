#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk){
    chunk->count = 0;
    chunk->capacity =0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initDynamicArray(&chunk->constants);
}

void freeChunk(Chunk* chunk ){
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeDynamicArray(&chunk->constants);
    initChunk(chunk);
}

//Appending bytes to the end of the chunk as bytecode
// 'Scanner' reads in symbols/unarys/literals and chucks em ere
void writeChunk(Chunk* chunk, uint8_t byte, int line) {
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code = GROW_ARRAY(uint8_t, chunk->code,
        oldCapacity, chunk->capacity);
    chunk->lines = GROW_ARRAY(int, chunk->lines,
        oldCapacity, chunk->capacity);
  }

  chunk->code[chunk->count] = byte;
  chunk->lines[chunk->count] = line;
  chunk->count++;
}

int addConstant(Chunk* chunk, Value value) {
  writeDynamicArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}


