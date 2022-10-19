#include <unistd.h>
#include <fcntl.h>
#include <ctype.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>


int main(int argc, char * argv[]){
    //checks the amount of command line arguments and prompts an error message
    if(argc != 6){
        printf("INVALID ARGUMENTS PROVIDED \n");
        exit(-1);
    }

//declaring the file descriptors and the buffer 
char buff; 
int fd1, fd2, fd3, fd4, fd5; 
char space = ' ';

//opening the file from the command line
if((fd1=open(argv[1],O_RDONLY ))==-1)
{
    printf("Error opening the input file \n");
            exit(-1);
}


if((fd2=open(argv[2],O_CREAT | O_RDWR ))==-1)
{
    printf("Error creating the alpha file \n");
            exit(-1);
}

if((fd3=open(argv[3],O_CREAT | O_RDWR ))==-1)
{
    printf("Error creating the num file \n");
            exit(-1);
}

if((fd4=open(argv[4],O_CREAT | O_RDWR ))==-1)
{
    printf("Error creating the other file \n");
            exit(-1);
}

if((fd5=open(argv[5],O_CREAT |O_RDWR ))==-1)
{
    printf("Error creating the copy file");
                exit(-1);
}

//while loop to read from the input file byte by byte 
while((read(fd1,&buff,1))==1){
//if the buff is a new line, 
if(buff == '\n'){
    write(fd2,&buff,1);
    write(fd3,&buff,1);
    write(fd4,&buff,1);
} else
//if the current buffer is a letter character (lowercase or uppercase), then it will print the buffer to the alpha file but spaces in the other files
if((buff >= 'a' && buff <= 'z' ) || (buff >= 'A' && buff <= 'Z' )){
    write(fd2,&buff,1);
    write(fd3,&space,1);
    write(fd4,&space,1);
}else if(buff >= '0' && buff <= '9'){ //if the current buffer is a numerical character, it will be added to the num file but spaces in the other files
    write(fd3,&buff,1); 
    write(fd2,&space,1);
    write(fd4,&space,1);
}else{ //for the characters that are characters that arent letters or numbers, it will be added to the other file and spaces will be added to other files
    write(fd4,&buff,1);
    write(fd2,&space,1);
    write(fd3,&space,1);
}

}
int offset = lseek(fd1, 0, SEEK_END);
close(fd1);
//lseeking the files to the beginning of the file 
lseek(fd2,0,SEEK_SET); 
lseek(fd3,0,SEEK_SET);
lseek(fd4,0,SEEK_SET); 

char buff2, buff3, buff4; 
//loop to read each of the files (loop size is based off of the file size of the input file)
for(int i =0; i < offset; i++){
    //reads files byte by byte
    read(fd2, &buff2 , 1); 
    read(fd3,&buff3,1); 
    read(fd4,&buff4,1); 
    //if the current character of all the buffers is a newline, then a new line is written to the copy file
     if(buff2 =='\n' && buff3 == '\n' && buff4=='\n'){
        char newline = '\n';
        write(fd5,&newline,1);

    }
    //if the current character of all buffers is a space, then a space is written in the copy file 
    if(buff2 ==' ' && buff3 == ' ' && buff4==' '){
        write(fd5,&space,1);

    }
    //if the current character of the alpha buffer is a letter, then the character is written into the copy file
    if((buff2 >= 'a' && buff2 <= 'z' ) || (buff2 >= 'A' && buff2 <= 'Z' )){
        write(fd5,&buff2,1);
    }
    //if the current character of the num buffer is a number, then the character is written into the copy file
    if(buff3 >= '0' && buff3 <= '9'){
       write(fd5,&buff3,1); 

    }
//if the current character of the other buffer is not equal to a space and a newline (representing the characters in the other file) then it is added to the copy file
     if(buff4 != ' ' && buff4 != '\n'){
        write(fd5,&buff4,1);
     }


}
//closing the file descriptors 
close(fd2);
close(fd3); 
close(fd4); 
close(fd5);


    return 0; 
}