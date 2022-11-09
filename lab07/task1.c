#include <sys/types.h> 
#include <signal.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h> 
static int alarm_fired = 0; 
//ding function is the signal handler 
void ding(int sig){
//sets the alarm_fired to 1
    alarm_fired = 1;
}

int main(){

    pid_t pid; 
   
    
    printf("alarm application starting \n"); 
//creating a child process
    pid = fork(); 
//declaring a sigaction struct and initializing the sigaction handler to ding()
     struct sigaction act;
    act.sa_handler = ding;
    switch(pid){
        //case if fork failed
        case -1:
        perror("Fork failed");
        exit(1); 
        //child process
        case 0: 
        sleep(5);
        kill(getppid(),SIGALRM);
        exit(0); 
        break;
        //parent process
        default:
        printf("Waiting for the alarm to go off \n"); 
    //sigaction waits for the signal to be sent and pauses the rest of the program until the signal is given
     sigaction(SIGALRM, &act, NULL);
     pause(); 
     //if the signal was sent and recieved sucessfully, it will print ding due to the 
    if(alarm_fired){
        printf("Ding \n");
        
    }
     printf("done\n");
     exit(0);
    }
     
}
