#include <unistd.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h>


int main(){
//running the executable using the symbolic link would be ./toHello
//making a new directory by using the symbolic link toDir21
if((mkdir("/root/COSC350/Lab04/Dir1/toDir21/Dir3",0777))==-1){
printf("Error making directory Dir3");
exit(-1);
}
//removing a file using the symbolic link toDir
if((remove("/root/COSC350/Lab04/Dir1/toDir21/hello"))==-1){
    printf("Error deleting file ");
    exit(-1);
}

return 0;
}