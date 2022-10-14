#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP)

int main(){
    //declaring a buffer the size of 32
    char buffer[32]; 
    int fd1; 
    int fd2; 
    char filename[50];
  printf("please print out the name of the file "); 
  scanf("%s",filename);

    if((fd1 =open(filename, O_RDONLY)) == -1){
        printf("Error opening file");
    }
//opening the file clone2 
    if((fd2 = open("clone2", O_RDWR | O_CREAT| O_EXCL,FILE_MODE))==-1){
    printf("File already Exsits!");
  }
  int nread;
  //copying the contents of the file 
  while ((nread =read(fd1, buffer, 32)) > 0) {
        write(fd2, buffer, nread);
  }
  close(fd1); 
  close(fd2);
  return 0; 
}