#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
/*
How my result compares to the previous program (fork1.c) result. In this program, the 
Parent process waited for the child process to finish before exiting the program. Unlike this
program, the last programs parent process did not wait for the child process to complete, therefore
the program exited while the child process was still happening, thus creating differing results 

*/
//prototype for convertToInt function 
int convertToInt(char * ar);

int main(int argc, char * argv[])
{
//checks the amount of arguments and exits if its invalid 
if(argc != 5){
    printf("ERROR 4 ARGUMENTS NEEDED"); 
    exit(-1);
}

pid_t pid;
char * message; 
int n;
int Nc = convertToInt(argv[1]);
int Np = convertToInt(argv[2]); 
int Tc = convertToInt(argv[3]); 
int Tp = convertToInt(argv[4]);
int sleeptime; 
int exitCode; 

printf("Fork program is Starting \n"); 
pid = fork();

switch(pid){
    case -1:
    perror("fork failed"); 
    exit(1);
    case 0:
    message = "This is the child";
    //number of iterations for the child process
    n = Nc;
    //setting the sleep time for the child process
    sleeptime = Tc;
    //setting the exitCode for the child process
    exitCode = 37;
    break;
    default:
    message = "This is the parent";
    //number of iterations for the parent process
    n = Np;
    //setting the sleep time for the parent process
    sleeptime = Tp;
    //setting the exitCode for the parent process 
    exitCode = 0;
    break;
}

for(; n > 0; n--){
    puts(message);
    sleep(sleeptime);
}
//parent class waits for the child process to end 
if(pid != 0){
    int stat_val; 
    pid_t child_pid; 
    //wait function is called to wait for the child process to end
    child_pid = wait(&stat_val);

    printf("Child has finished: PID = %d\n", child_pid);
    //if the child process ended normally, it will prompt a message. if not it will also prcess a message
    if(WIFEXITED(stat_val))
        printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
    else
    {
        printf("Child terminated abnormally \n"); 
    }
}
exit(exitCode);
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