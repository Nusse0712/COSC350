#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_PATH "task4_fifo"
#define MAX_BUF_SIZ 255
/*
i used the command mkfifo -m 0777 task4_fifo to make the fifo. 
i could use mkfifo() in the program to create the fifo 

*/
int main()
{
    int data_processed; 
    int ret_val; 
    int fd1, fd2;
    pid_t pid; 
    const char some_data[] = "123"; 
    char * buffer = malloc(sizeof(some_data));
    if((pid=fork())<0){
        printf("fork failed\n"); 
        exit(1);
    }
    if(pid == 0){
 fd1 = open(FIFO_PATH, O_WRONLY); 
 data_processed =write(fd1, some_data, strlen(some_data));
 printf("Wrote %d bytes\n", data_processed);
 close(fd1); 
    exit(0);
    }else{
fd2 = open(FIFO_PATH, O_RDONLY); 
data_processed = read(fd2, buffer, sizeof(buffer)); 
printf("Read %d bytes: %s\n",data_processed,buffer); 
exit(0);
    }
return 0;
    

}
