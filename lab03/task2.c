#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{
  int fd1; 
  int fd2; 
  char b1; 
  //opening the file foo, prompts an error if it cant
  char filename[50];
  printf("please print out the name of the file "); 
  scanf("%s",filename);
  if((fd1 = open(filename, O_RDWR))== -1){
    printf("Error opening file"); 
   
  }
  //creating the file clone1 and printing an error if the file already exists
  if((fd2 = open("clone1", O_RDWR | O_CREAT| O_EXCL,FILE_MODE))==-1){
    printf("File already Exsits!");
  }

  int nread; 
//copying the contents of foo to clone1 byte by byte
  while ((read(fd1, &b1, 1))==1){
    write(fd2, &b1, 1);
  }
//closing the files
  close(fd1); 
  close(fd2); 


return 0; 
}
