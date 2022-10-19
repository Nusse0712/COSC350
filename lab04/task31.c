#include <unistd.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <stdio.h> 
 #include <stdlib.h>

int main(){
//task 3.1 
//creating the directory Dir1
if((mkdir("/root/COSC350/Lab04/Dir1",0777))==-1){
    printf("Error making directory Dir1");
    exit(-1); 

}
//creating the directory Dir2 
if((mkdir("/root/COSC350/Lab04/Dir2",0777))==-1){
    printf("Error making directory Dir2");
    exit(-1); 
}

//creating the directory Dir21 inside of directory1
if((mkdir("/root/COSC350/Lab04/Dir2/Dir21",0777))==-1){
    printf("Error making directory");
    exit(-1);
}

//creating a new link for the file hello at Dir21
if((link("/root/COSC350/Lab04/hello","/root/COSC350/Lab04/Dir2/Dir21/hello"))==-1){
    printf("Error Linking file"); 
    exit(-1);
}

//unlinking the original link to move the file to the new link
if(unlink("/root/COSC350/Lab04/hello")==-1){
    printf("Error Unlinking file");
    exit(-1);
}

//creating symbolic link for Dir21 called toDir21
if((symlink("/root/COSC350/Lab04/Dir2/Dir21","/root/COSC350/Lab04/Dir1/toDir21"))==-1){
    printf("error creating symbolic link toHello ");
    exit(-1);
}

//creating a symbolic link for hello called toHello
if((symlink("/root/COSC350/Lab04/Dir2/Dir21/hello","/root/COSC350/Lab04/Dir1/toHello"))==-1){
    printf("error creating symbolic link toHello ");
    exit(-1);
}









return 0;
}


