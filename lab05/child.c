#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
//child process program 

//prototype of function convertToInt
int convertToInt(char * ar);


int main(int argc, char * argv[]){
    //the Nc and Tc values are the first and second arguments being passed through 
    //have to be converted to an int before being used 
    int Nc = convertToInt(argv[0]); 
    int Tc = convertToInt(argv[1]);
    //the message is the third argument being passed 
    char * message = argv[2]; 
   



    for(; Nc > 0; Nc--){
    //statement that prints the PID of the child process and the message. Sleep and iteration amount depends on Tc and Nc 
    printf ("Child Process ID = %d \n", getpid());
    puts(message);
    sleep(Tc);
}
exit(37);
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