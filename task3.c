#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char * argv[]){

    pid_t pid; 
    int cout;
    char * string = "Hi, Mom \0";
//creating the file foo
 if((cout=open("foo",O_CREAT|O_RDWR,S_IREAD|S_IWRITE))==-1){
        printf("Error opening file"); 
        exit(0);
    }
   //creating a new child process with fork 
    pid = fork(); 

   //switch statement for the process
    switch(pid){
        case -1: //case if the fork fails
        perror("Fork failed"); 
        exit(-1);
        break; 
        case 0:  //child process
        //writes the string to the file foo
         if((write(cout,string,strlen(string))==-1)){
            printf("Write error!"); 
            exit(-1);
         }
         
        exit(0);
        break;
    }
    if(pid != 0){ //the parent process
        int stat_val; 
        pid_t child_pid;
        char buff;
        char * string2 = "My Son Said \0";
        //the parent process waits for the child process to finish before continuing 
        child_pid = wait(&stat_val);
       //writes the string to standard output
       if(write(1,string2,strlen(string2))==-1){
        printf("Write Error!"); 
        exit(0);
       }
        //using lseek to seek to the beginning of the file
        lseek(cout,0,SEEK_SET); 
        //the buffer reads the file byte by byte and writes to the standard output
        while((read(cout, &buff, 1))==1){
            write(1,&buff,1);
        }
    //closing the file
    close(cout); 
        
    exit(0);
    }
}