#include <signal.h> 
#include <stdio.h> 
#include <unistd.h> 
/* 
I used the ^Z to run the program in the background
I used the command kill -9 pid  to terminate the process


*/
//ouch is the signal handler
void ouch(int sig){
    //prints to the user that it got the signal
    printf("OUCH - I got a signal %d\n",sig); 
}

int main(){
    //declaring a new sigaction struct
    struct sigaction act; 
//initializing the sa_handler to the signal handler ouch() 
    act.sa_handler = ouch; 
//emptying the signal set for the siaction struct
    sigemptyset(&act.sa_mask); 
//setting the sa_flags to SA_RESETHAND
    act.sa_flags = SA_RESETHAND; 
    //sigaction to send signal to signal handler
    sigaction(SIGINT, &act, 0); 
    //infinite loop 
    while(1){
        printf("Hello World \n");
        sleep(1);
    }
}
