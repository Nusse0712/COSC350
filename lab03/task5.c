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
if((fd1 = open(filename,O_RDWR)) == -1)
{
        printf("error opening file");
}
//creating the file foorev
if((fd2 = open("foorev",O_RDWR | O_CREAT | O_EXCL, FILE_MODE)) == -1)
{
        printf("file foorev already exsists");
}
//offset is equal to the last position of the first file
  offset = lseek(fd1, -1, SEEK_END);

//loop that reads each character of the file, starting from end of input
//writes to beggining of write file and then sets the cursor to next posistion
while((read(fd1, buff, 1)==1)&&(offset>=0)){

        write(fd2, buff, 1);
        offset--;
        lseek(fd1, offset, SEEK_SET);
}
close(fd1);
close(fd2); 

return 0;
}