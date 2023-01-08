#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <sys/wait.h>
#define READ_END 0 
#define WRITE_END 1


int main(){
int data_processed; 
int file_pipes[2]; 
char buffer[BUFSIZ + 1]; 
char buff[BUFSIZ+1];
pid_t fork_result; 

memset(buffer, '\0', sizeof(buffer)); 

if(pipe(file_pipes) == 0){

    fork_result = fork(); 
    if(fork_result == (pid_t)-1){
     fprintf(stderr, "Fork Failure"); 
     exit(EXIT_FAILURE); 
    }

    if(fork_result ==0){
        close(file_pipes[READ_END]); 
        sprintf(buffer,"%d", file_pipes[WRITE_END]); 
        (void)execl("pipe4", "pipe4", buffer, (char*)0); 
        exit(EXIT_FAILURE);
    }else{
         close(file_pipes[WRITE_END]); 
        int stat_val; 
        fork_result = wait(&stat_val); 
        data_processed = read(file_pipes[READ_END],buff,BUFSIZ);
       
       
        printf("%d - read %d bytes, %s \n",getpid(),data_processed,buff); 
    }
}
exit(EXIT_SUCCESS); 

}