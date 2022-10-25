
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>

//function that decides if a character is a numerical character or not
int isNumeral(char  achar){
    if(achar >= '0' && achar <= '9'){
        return 1;
    }else{
        return 0;
    }
}
//signal handler function 
void sigalrm()
{
   printf("Signal sent to child Process \n");
}




int main(int argc, char *argv[])
{
//declaring file descriptors 
int inputs, chout, pout;
char buff;
//checking the argument count of the command line and exits the program if it is invalid
if (argc != 2){
printf("ERROR: INVALID ARGUMENTS\n");
exit(-1);
}
//opening the input file
if((inputs = open(argv[1], O_RDONLY))==-1){
printf("ERROR: FILE CANT BE OPENED \n"); 
exit(-1); 
}
pid_t pid;
//creating a child process with fork
if((pid = fork())<0){
    printf("FORK ERROR"); 
    exit(-1);
}
//child process
if (pid == 0)  
{
//recieves signal from the sigalrm handler that signals when the parent process is over
signal(SIGALRM, sigalrm);  
//pauses the program until the signal is sent from the parent process
pause(); 
//opening the child txt file
if ((chout = open("child.txt", O_WRONLY|O_CREAT, S_IREAD|S_IWRITE)) == -1){
printf("ERROR CREATING OUTPUT FILE");
exit(-1);
}
//reading the file byte by byte
while(read(inputs, &buff,1)==1){
//if the isNumeral function of the character is 0 (signaling that its not a Numerical character)
 if(isNumeral(buff)==0){

     //write the current character to the child.txt
if (write(chout, &buff, 1) != 1){
printf("Write Error");
exit(-1);
}
}

}
exit(0);
}
else  //Parent Process
{
    //opening the parent.txt file for writing
if ((pout = open("parent.txt", O_WRONLY|O_CREAT, S_IREAD|S_IWRITE)) == -1){
printf("ERROR CREATING OUTPUT FILE");
exit(-1);
}

//reading the file one byte at a time 
while(read(inputs, &buff,1)==1){
//if the isNumeral function returns a 1 (signaling its a numeral character) then it is written to the parent file
if(isNumeral(buff)==1){

if (write(pout, &buff, 1) != 1){
printf("Write Error");
exit(-1); 
}
}
}
//lseek the inputs file back to the beginning of the file
lseek(inputs, 0, SEEK_SET);
//sending a signal to the child process so it can start reading the file 
kill(pid,SIGALRM);
}



exit(0);

}
