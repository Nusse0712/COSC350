#include <stdio.h>
#include <strings.h>
#include <unistd.h> 
//enviroment variables 
extern char **environ;
//function mygetenv passes through a char pointer 
char * mygetenv(char * name){

char **env = environ;

//iterates through the list of enviroment variables
while(*env != NULL){
//if statment that compares the bytes of the name and the enviroment variable
if((bcmp(name, *env, sizeof(*name)))==0){
    //if they are the same it returns the enviroment variable 
return *env; 
}
//iterating through the list of enviroment variables 
 *env++;
}
//returning NULL if the name cannot be found 
return NULL;
}

int main(){
    //declaring a string called path 
    char * name = "PATH"; 
    //using the mygetenv function
    char * env = mygetenv(name);
    //printng the result of the mygetenv function 
    printf("%s \n",env);
    name = "HOME"; 
    env = mygetenv(name);
    printf("%s \n",env);

}