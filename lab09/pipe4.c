#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

int main(int argc, char * argv[])
{
    int data_processed; 
    int file_descriptor; 
    const char some_data[] = "123456"; 

 
    sscanf(argv[1], "%d", &file_descriptor); 
    data_processed = write(file_descriptor, some_data, strlen(some_data)); 

    printf("%d - wrote %d bytes\n",getpid(),data_processed); 

    exit(EXIT_SUCCESS); 
}