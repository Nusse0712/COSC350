#include <stdio.h>

int convertToInt(char * ar);
int main(int argc, char *argv[]){
    //using argc to check if there is a command line argument being passed
    if(argc < 2){
        printf("There is not at least one integer on the command line ");
    }else{

    int sum =0;
    int num =0; 
    //for loop for getting the sum. num is assigned to the command line being passed through the convertToInt function 
    for(int i = 0; i < argc; i++){
       num = convertToInt(argv[i]);
       sum = sum + num; 
       num = 0;
    }
    printf("The sum is = %d ",sum);
    }
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
