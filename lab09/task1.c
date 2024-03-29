#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#define READ_END  0
#define WRITE_END  1
/*
Task1 Part C: when the read and write commands were reversed,
there was no output to the program. This is because the program was 
trying to read from the pipe, which was empty. It goes on forever because
read is trying to read fron an empty pipe that is not closed
*/
int main()
{
    int data_processed; 
    int file_pipes[2]; 
    const char some_data[] = "123"; 
    char * buffer = malloc(sizeof(some_data));
    int bufferSize = sizeof(buffer);

    if(pipe(file_pipes) == 0){
data_processed = write(file_pipes[WRITE_END], some_data, strlen(some_data));

printf("Wrote %d bytes\n", data_processed); 
data_processed = read(file_pipes[READ_END],buffer,sizeof(buffer)); 
printf("Read %d bytes: %s\n",data_processed,buffer); 
exit(EXIT_SUCCESS);
    }
exit(EXIT_FAILURE);
}