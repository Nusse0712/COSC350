#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP)

int main(){

int offset;
int fd1;
int fd2;
char buff[1024];
 char filename[50];
  printf("please print out the name of the file "); 
  scanf("%s",filename);
//opens the file foo to be read 
if((fd1= open(filename,O_RDWR))== -1){

        printf("Error opening file");
}
//creates the file foorev2 to be written in 
if((fd2= open("foorev2",O_RDWR | O_CREAT | O_EXCL, FILE_MODE))==-1){

        printf("Error: file already exsists");
}

int writenum = 0;
offset= lseek(fd1,-1,SEEK_END);

//loop that reads from input file and writes the reverse in the output
//uses pread to get the first character from the offset (end of the file)
while((pread(fd1,buff,1,offset)==1)){
//writes the character to the beginning of the output file
        pwrite(fd2,buff,1,writenum);
//decrements the reading offset while incrementing writing offset
        offset--;
        writenum++;
}
//closing the files
close(fd1);
close(fd2);












return 0;
}