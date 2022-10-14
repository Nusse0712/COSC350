#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/stat.h> 

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP)

int main(){

int offset;
int fd1;
int fd2;
int fd3;
char buff1[1024];
char buff2[1024];
//opening foo for reading
 char filename[50];
  printf("please print out the name of the file "); 
  scanf("%s",filename);

if((fd1 = open(filename,O_RDWR))== -1)
{
        printf("Error opening file");
}
//creating foo12 and prompting a message if the file was already created
if((fd3 = open("foo12",O_RDWR | O_CREAT | O_EXCL, FILE_MODE))== -1)
{

        printf("File is already created");
}

//reading from the file and writing to the output
int nread;
while((nread=read(fd1, buff1, 32)) > 0)
{
        write(fd3,buff1,nread);

}
//closing both files
close(fd1);
close(fd3);
 char filename2[50];
  printf("please print out the name of the second file "); 
  scanf("%s",filename2);
//opening foo1 and prompting a message if there is an error
if((fd2 = open(filename2,O_RDWR))== -1)
{
        printf("Error opening file");
}

//opening the output file and seeking to the end of the output file
fd3 = open("foo12",O_RDWR);
lseek(fd3, 0, SEEK_END);

//reading from the second file and writing this to the output
int nread2;
while((nread2=read(fd2, buff2, 32)) > 0)
{
        write(fd3,buff2,nread2);
}
close(fd2);
close(fd3); 


return 0;
}