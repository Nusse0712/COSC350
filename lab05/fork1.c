#include <sys/types.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

int convertToInt(char * ar);

int main(int argc, char * argv[])
{
//checking the amount of arguments passed through the command line and exiting if its invalid
if(argc != 5){
    printf("ERROR 4 ARGUMENTS NEEDED"); 
    exit(-1);
}

pid_t pid;
char * message; 
int n;
//converting the command line arguments to ints
int Nc = convertToInt(argv[1]);
int Np = convertToInt(argv[2]); 
int Tc = convertToInt(argv[3]); 
int Tp = convertToInt(argv[4]);
int sleeptime; 
//forking the process into two processes
printf("Fork program is Starting \n"); 
pid = fork();

switch(pid){
    //case if fork failed
    case -1:
    perror("fork failed"); 
    exit(1);
    //child process
    case 0:
    message = "This is the child";
    //number of iterations for the child process
    n = Nc;
    //setting the sleep time for the child process
    sleeptime = Tc;
    break;
    //parent process
    default:
    message = "This is the parent";
    //number of iterations for the parent process
    n = Np;
    //setting the sleep time for the parent process
    sleeptime = Tp;
    break;
}
//printing out the message based on the value of n and sleeptime
for(; n > 0; n--){
    puts(message);
    sleep(sleeptime);
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
