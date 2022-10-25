#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

int convertToInt(char * ar);

int main(int argc, char * argv[])
{
if(argc != 5){
    printf("ERROR 4 ARGUMENTS NEEDED"); 
}

pid_t pid;
char * message; 
int n;
int Np = convertToInt(argv[2]); 
int Tp = convertToInt(argv[4]);
int sleeptime; 

printf("Fork program is Starting \n"); 
//forking the process
pid = fork();

switch(pid){
    case -1:
    perror("fork failed"); 
    exit(1);
    case 0:
    message = "This is the child";
    //arguments array is made up of the 1st and 3rd command argument (Nc and Tc) and the message of the argument 
    char * args[] = {argv[1],argv[3],message,NULL}; 
    //the execv function is called to open a process and pass the args array through that process
    execv("/root/COSC350/Lab05/child", args);
    break;
    default:
    message = "This is the parent";
    //number of iterations for the parent process
    n = Np;
    //setting the sleep time for the parent process
    sleeptime = Tp;
    //setting the exitCode for the parent process 
   
    break;
}
//printing out based on the value of n 
for(; n > 0; n--){
    //printing the pid of the parent class everytime the loop is iterated 
    printf ("Parent Process ID = %d \n", getpid());
    //prints the message everytime the loop iterates 
    puts(message);
    //sleep depends on sleeptime
    sleep(sleeptime);
}
//parent waits for the child process to finish 
if(pid != 0){
    int stat_val; 
    pid_t child_pid; 
//the wait function is used to wait for the child process to finish 
    child_pid = wait(&stat_val);

    printf("Child has finished: PID = %d\n", child_pid);

    if(WIFEXITED(stat_val))
        printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
    else
    {
        printf("Child terminated abnormally \n"); 
    }
}
exit(0);
}

int convertToInt(char * ar){
 int num = 0; 

 //for loop that converts the string to an int
 //goes through the string character by character and updates the numb
 for (int i = 0; ar[i] != '\0'; i++) {
         if (ar[i]> '9' || ar[i]<'0'){
            return 0; //returns 0 when any character in the string is greater than the character 
         }
     num = num*10 + ar[i] - '0';
 }
 
 return num;
}