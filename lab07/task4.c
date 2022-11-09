#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>
static int sigusr1_fired = 0; 
static int sigusr2_fired = 0; 
//signal handler named handler
void handler(int sig)
{   //if the signal is SIGUSR1 then 1 is assigned to the signalusr1_fired variable
    if(sig == SIGUSR1){
        sigusr1_fired = 1;
    } 
     //if the signal is SIGUSR2 then 1 is assigned to the signalusr2_fired variable
    if(sig == SIGUSR2){
        sigusr2_fired = 1;
    }

}


int main(int argc, char * argv[]){

pid_t pid, pid2; 

//creating the first child process
if((pid = fork())<0){
    printf("Fork Failed\n"); 
    exit(0);
}


if(pid == 0){ //child process
    //sends a SIGUSR1 to the parent process
    kill(getppid(),SIGUSR1);
    exit(0);
}
else if(pid > 0){ //parent process
//recieves signal from the signal handler
(void) signal(SIGUSR1,handler);
pause(); 
//if the signal handler recieved the signal from the child process, then it prints hi honey anything wrong?
if(sigusr1_fired){
    printf("hi honey anything wrong \n");
}

//creating the second child class
   if((pid2 = fork())<0){
    printf("Fork Failed \n"); 
    exit(0);
   }
   if(pid2 == 0){ //second child process sends signal to parent process
        kill(getppid(),SIGUSR2);
        exit(0);
    }
   if(pid2 > 0){ 
    //parent process of the second child recieves signal from signal handler 
       (void) signal(SIGUSR2,handler);
       pause(); 
       //if the signal was recieved it prints the message
       if(sigusr2_fired){
         printf("do you make trouble again \n");
       }
      
   }
}
    return 0; 
}
