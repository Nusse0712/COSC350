#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

int main(int argc, char * argv[])
{
    int data_processed; 
    int file_descriptor; 
    int file_descriptor2;
    const char some_data[] = "Hi Mom"; 
    char buff[BUFSIZ+1]; 

 
    sscanf(argv[1], "%d", &file_descriptor); 
    sscanf(argv[2],"%d",&file_descriptor2);
    data_processed = read(file_descriptor2, buff, BUFSIZ); 
     printf("%d - read %d bytes, %s \n",getpid(),data_processed,buff); 
    data_processed = write(file_descriptor, some_data, strlen(some_data)); 

    printf("%d - wrote %d bytes\n",getpid(),data_processed); 

    exit(EXIT_SUCCESS); 
}