#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#include "chunk.h"
#include "debug.h"

// Recursive descent parser for my toy programming language

int interactiveMode();
int executeCommand(char ** string);

int main(int argc, char * argv[]){

    // // Currently intended to start live coding, changed to take in input from the command line
    // if(argc == 1 ){

    //     // live_coding()
    //     // repl -? read-eval-print loop 
    //     //interactiveMode();
        
    // // Take in input from file and exectue
    // }else if(argc == 2){
    //     // Read file path and execute code from file
    //     // argc is always 1, second arg is filepath


    // // Enter live coding mode and execute queries from the shell
    // }else{

    //     // print correct usage to command line -> ./parser [path]
    // }

    //clean everything up

    return 0;

}

// Interactice coding loop, parse and execute user input from the terminal
// int interactiveMode(){
//     // A REPL loop should be able to take in multi line input and have no limit to what 
//     // it can take in. The limiter should be the method by which it's being accessed

//     struct DynamicArray buffer = {
//         .size = BUFFERSIZE,
//         .arr = malloc(BUFFERSIZE * sizeof(char))
//     };


//     int counter = 0;
//     // This is the repl loop, terminates on program exit otherwise infinite
//     for(;;){

//         print("> ");

//         // fgets each line in one at a time
//         while(fgets(buffer.arr,buffer.size,stdin)){
//             // reach the terminal character from fgets or reach the max buffer size first
//             // if max buffer size reached first, resize buffer THEN feed in input
//         }

//         // Resize buffer when needed
//         if(counter == buffer.size){
//             if(resizeBuffer(&buffer) != 0){
//                 // Command too big, exit execution
//                 fprintf(stderr,"Failed to resize buffer");
//                 return -1; 
//             };
//         }

//         // fill the array up with ints represented as chars
//         //buffer.arr[counter] = counter +'0';

//         interpret();
//         counter++;
//     }

//     // Output telemetry data?
//     printf("Final buffer size: %d", buffer.size);

//     // Free up everything, be a good lad
//     free(buffer.arr);
//     return 0;
// }


// string comes from file, command line or repl loop
int executeCommand(char ** string ){

    if(string){}
    // Scanner

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);

        
    return 0;
}