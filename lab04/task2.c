#include <unistd.h>
#include <fcntl.h>
#include <ctype.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>



int palind(int fd1, int fd2){
    char buff1; 
    char buff2; 
   //seeks fd2 to the end of the file
   lseek(fd2,0,SEEK_END);
   //initializing a counter variable i
   int i = 1;
   
   //reading each file byte by bye
   while(read(fd1,&buff1,1)==1){
    //checks to see if the current forwards chracter is a space. If the character is a space then it reads the next character
   if(buff1==' '){
     read(fd1,&buff1,1);
   }

    //lseeking to the current cursor of fd2 (based on value of negative i)
    lseek(fd2,-i,SEEK_END);
    //reads the character from fd2 to second buffer
    read(fd2,&buff2,1);
    
    //checks to see if the current backwards chracter is a space. If the character is a space then seeks to two spaces
    //records the next character
    if(buff2==' '){
        lseek(fd2,-2,SEEK_CUR);
        read(fd2,&buff2,1);
        i++;
    }

    
//checks if the forward and backwards characters are the same, if they are it continues with the loop
//if they're not the same, then function returns 0
    if(buff1 != buff2){
        return 0;
    }

    //i increments after every loop
    i++; 
  
   }
//returns 1 if 
     return 1; 
}


int main(int argc, char * argv[]){
//checks if the user entered one command line argument
if(argc != 2){

    printf("ERROR: ENTER 1 FILENAME");
    exit(-1);
}
//declaring file descriptors
int fd1, fd2; 

//opening the file passed through the command line at fd1
if((fd1=open(argv[1],O_RDWR ))==-1)
{
    printf("Error opening the file");
    exit(-1);
}
//opening the flle again at fd2
if((fd2=open(argv[1],O_RDWR ))==-1)
{
    printf("Error opening the file");
    exit(-1);
}
//int num is the outcome of the palind() function 
int num = palind(fd1,fd2);
//if num  is equal to 1, the string is a palindrome, if num equals 0 then the word is not a palindrome
if(num==1){
    printf("The word is a palindrome!! \n");
}else{
    printf("The word is not a palindrome \n ");
}
    return 0; 
}
