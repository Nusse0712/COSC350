#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 256
int main(int argc, char * argv[]){
//checking the amount of command line arguments 
if(argc != 3){

printf("invalid arguments!!!\n");
exit(1); 
}

int argLength = 0; 
//determining the length of all arguments 
for(int i = 1; i < argc; i++){

    argLength += strlen(argv[i]);
}
//mallocing a char array based on the argument length
char * cmd = (char*)malloc(argLength*sizeof(char));

//concatinating all the arguments together into one command string
for(int i = 1; i < argc; i++){

    sprintf(cmd,"%s %s",cmd,argv[i]);
}

char * buff =(char*) malloc(MAXLENGTH *sizeof(char)); 

FILE * cmdStream; 
//using popen to read in the command 
if((cmdStream = popen(cmd, "r"))!= NULL){
 //getting the string from the cmdStream and printing the string 
 while(fgets(buff,MAXLENGTH,cmdStream) !=NULL){
    printf("%s",buff);
 }

}
//closing the command stream
pclose(cmdStream); 
exit(0);
}