#include <unistd.h>
#include <fcntl.h>
#include <ctype.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
int convertToInt(char * ar);

int convIntToStr(char * str, int x){

    sprintf(str, "%d",x);
    return (strlen(str));

}

int main(int argc, char * argv[]){
//checks to see if there is a command line argument or not
if(argc != 2){

    printf("ERROR: ENTER 1 ARGUMENT");
    exit(-1);
}

//declare the buffer to read the file and the file descriptor
char buff; 
int fd1, fd2; 
int offset;
char * numArray; 


//opening the file from the command line
if((fd1=open(argv[1],O_RDWR ))==-1)
{
    printf("Error opening the file");
    exit(-1);
}


//finding the size of the file 
offset = lseek(fd1,0,SEEK_END); 
//dynamically creating an array of chars 
numArray = (char*) malloc(offset * sizeof(char));
//lseek back to the end of the file
lseek(fd1,0,SEEK_SET);

int i =0; 
//reading from the file byte by byte
while ((read(fd1, &buff, 1))==1){

//checks if the char is a digit of not, if not it adds to the array
    if(isdigit(buff)!=0){
        numArray[i] = buff;
        i++;
    }
    
  }
  int sum;

  //converting the char array into an int
   sum = convertToInt(numArray);

   //adding 10 to the sum
   sum = sum + 10; 


//defining the output string and the stringlength 
  char * output; 
  int sumLength; 

//converting the int back into string
  sumLength = convIntToStr(output, sum);
  
  write(1,output,sumLength);
  

close(fd1);


return 0;
}

int convertToInt(char * ar){
 int num = 0; 

 //for loop that converts the string to an int
 //goes through the string character by character and updates the numb
 for (int i = 0; ar[i] != '\0'; i++) {
         if (ar[i]> '9' || ar[i]<'0'){
            return 0; //returns 0 when any character in the string is greater than the character 
         }
     num = num*10 + ar[i] - '0';
 }
 
 return num;
}


 



