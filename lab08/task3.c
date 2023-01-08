#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAXLINE 256

int main(){
int n; 
int fd[2]; 
int size; 
int int1, int2;

pid_t pid; 

char reLine[MAXLINE]; 
char wrLine[MAXLINE]; 
//creating the pipe 
if(pipe(fd) < 0){
    printf("PIPE FAILED \n"); 
    exit(1);
}
//creating a fork
if((pid = fork())<0){
printf("FORK ERROR \n"); 
exit(1);
}

if(pid > 0){ //parent process 
    //closing th read pipe 
    close(fd[0]);
    //prompting the use to enter two integers 
    printf("please enter two integers \n");
    //while loop that keeps asking the user to print two different integers 
    while ( (size = read(STDIN_FILENO, wrLine, MAXLINE)) > 0)
{
//writing to the pipe 
write(fd[1], wrLine, size);

}
}else{ //child process
    //closes the write pipe
    close(fd[1]);
    //reads from the pipe and parses the string into two different integers
    while((n = read(fd[0],reLine,MAXLINE))> 0){
        if (sscanf(reLine, "%d%d", &int1, &int2) == 2)
{
//saves the sum of the two integers to reLine   
sprintf(reLine, "%d\n", int1 + int2);
//prints the sum
printf("the sum of %d and %d is %s",int1,int2,reLine);
printf("please enter two integers \n");  

}else{
    //if the user prints invalid arguments, then it tells the user
    char * error = "invalid number of arguments \n";
    int errorLength = strlen(error);
    write(STDOUT_FILENO, error, errorLength);
    printf("please enter two integers \n");  
}



    }
}

    exit(0); 
}