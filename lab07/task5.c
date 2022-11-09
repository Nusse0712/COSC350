#include <bits/types/sigset_t.h>
#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h> 
#include <stdlib.h> 
#include <sys/types.h>


int main(){
    //declaring two sets of sigsets
    sigset_t sigmask ,emptymask; 
    //making the emptymask sigset empty
    sigemptyset(&emptymask);
    //adding the SIGINT AND THE SIGQUIT signal to the signal set
    sigaddset(&sigmask, SIGINT); 
    sigaddset(&sigmask, SIGQUIT); 
    //calling the sigprocmask function to block those signals in the sigmask set
    sigprocmask(SIG_BLOCK, &sigmask, NULL);
     
    printf("Here comes the first loop \n"); 
//printing out the first loop
    for(int i = 1; i <= 5; i++){
        printf("%d \n",i);
        sleep(1);
    }
    //ignores the functions of the SIGINT and the SIGQUIT signal 
      signal(SIGINT,SIG_IGN);
      signal(SIGQUIT,SIG_IGN);
    //updating the mask to an empty mask to change the current mask
    sigprocmask(SIG_SETMASK, &emptymask,  NULL); 
    //deleting the SIGQUIT signal from the sigmask set
    sigdelset(&sigmask, SIGQUIT); 
    //updating the mask to block the signal SIGINT but not SIGQUIT
    sigprocmask(SIG_BLOCK, &sigmask , NULL); 
    //using the signal function to give the SIGQUIT signal its default function 
    signal(SIGQUIT,SIG_DFL); 
    //printing the second loop
    printf("Second Loop \n"); 
     for(int i = 1; i < 5; i++){
        printf("%d \n",i);
        sleep(1);
    }
    
}
