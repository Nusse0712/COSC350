#include <unistd.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <dirent.h>
#include <string.h>

int main(int argc, char * argv[]){
    if(argc != 3){
        printf("TWO ARGUMENTS NEEDED");
    } 
    char  currPath[50];
    char  desPath[50];
//checks the second command line argument(path to directory) exists, if it doesnt
//a directory with the path
    if((opendir(argv[2]))==NULL){
        mkdir(argv[2], 0777); 
    }
    
    //concatinating the paths together
    sprintf(currPath,"/root/COSC350/Lab04%s%s","/",argv[1]);
    sprintf(desPath,"%s%s%s",argv[2],"/",argv[1]);
   
   //linking the file to the new directory 
   if((link(currPath ,desPath))==-1){
   printf("Error Linking File");
   }
    //unlinking the file from the old directory
   if((unlink(currPath))==-1){
    printf("Error Unlinking File");
   }

  
 return 0;   
}