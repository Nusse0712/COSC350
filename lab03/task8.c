#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
//sets the file mode to rw-rw-rw-
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)


int main(int argc, char *argv[]){
//gives the user an error message if there were not enough arguments present
    if(argc != 2){
        printf("Error: not enough arguments provided");
        exit(-1);
    }
    int fd1; 
    int fd2; 
    char buffer[1]; 
//opening the file with read only, gives user error message if otherwise
if((fd1=open(argv[1],O_RDONLY))==-1){
    printf("Error Opening INPUT File"); 
    exit(-1); 
}
//opening the file with the mode rw-rw-rw-, igves the user an error message if otherwise
if((fd2=open(argv[2],O_RDWR))==-1){
    printf("Error Opening OUTPUT File"); 
    exit(-1); 
}
int nread;
char c;
//creating temporary buffer to break down contents on file
char temp[4];
temp[0]=' ';
//while loop to read through the file
while((nread = read(fd1, buffer,1))==1){
//turning the buffer into a num
int num =(*buffer - '\0');

//for loop to break down the num and assign it to temp
for(int i =3; i>=1;i--){
   temp[i]=(num%10) + '0'; 
   num /= 10;
}

//writing to the output file using temp 
write(fd2,temp,4);
}

//closing the file
close(fd1); 
close(fd2); 

}

