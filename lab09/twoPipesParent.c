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
int file_pipes2[2]; 
char arg1[BUFSIZ + 1]; 
char arg2[BUFSIZ+1];
char buff[BUFSIZ+1];
pid_t fork_result; 

memset(arg1, '\0', sizeof(arg1)); 
memset(arg2, '\0', sizeof(arg2)); 
if(pipe(file_pipes) == 0){
    if(pipe(file_pipes2)==0){
    fork_result = fork(); 
    if(fork_result == (pid_t)-1){
     fprintf(stderr, "Fork Failure"); 
     exit(EXIT_FAILURE); 
    }

    if(fork_result ==0){
        close(file_pipes2[WRITE_END]); 
        close(file_pipes[READ_END]); 
        sprintf(arg1,"%d", file_pipes[WRITE_END]); 
        sprintf(arg2,"%d", file_pipes2[READ_END]);
        (void)execl("twoPipesChild", "twoPipesChild", arg1,arg2, (char*)0); 
        exit(EXIT_FAILURE);
    }else{
        close(file_pipes2[READ_END]);
        close(file_pipes[WRITE_END]); 
      
         char  message[] = "Hi, there kiddo";
        data_processed = write(file_pipes2[WRITE_END],message,strlen(message)); 
        printf("%d - wrote %d bytes \n",getpid(),data_processed);
        
        data_processed = read(file_pipes[READ_END],buff,BUFSIZ);
       
       
        printf("%d - read %d bytes, %s \n",getpid(),data_processed,buff); 
    }
}
}
exit(EXIT_SUCCESS); 

}