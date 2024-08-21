#include <stdio.h>
#include <stdlib.h>

// Parse and execute 1 command at a time??
#define BUFFERSIZE 100
#define MAXBUFFSIZE 100000

// If command size larger than buffer, resize, simple as
int resizeBuffer(char ** buffer, int* buff_len){
    *buff_len = *buff_len * 10;

    if(*buff_len > MAXBUFFSIZE){
        // Buffer too big
        return 1;
    }
    
    char * new_buf = malloc(*buff_len * sizeof(char)); 

    for(int i = 0; i<*buff_len; i++){
        new_buf[i] = (*buffer)[i];
    }

    free(*buffer);
    *buffer = new_buf;

    printf("buffer resized to %d\n", *buff_len);
    return 0;
}

// Parser does not need to hold state so this should be a fairly simple line by line 
// parser when it executes. 
int main(int argc, char * argv[]){

    // Store the buffer size in a value and update the buffersize as we go
    int* buf_size = malloc(sizeof(int));
    *buf_size = BUFFERSIZE;
    
    // Init buffer
    char * buffer = malloc(*buf_size * sizeof(char));

    // Loop through arguments and parse them as NOSQL/S3 commands
    for(int i = 0; i<100000; i++){
        if(i == *buf_size){
            if(resizeBuffer(&buffer, buf_size) == 1){
                // Command too big, exit execution
                printf("Command too big, enter a command less than 100,000 characters long");
                return -1; 
            };
        }
        buffer[i] = i +'0';
    }

    printf("Final buffer size: %d", *buf_size);

    free(buffer);
    return 0;
}