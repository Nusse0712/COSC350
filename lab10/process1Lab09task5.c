#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h> 
#include <unistd.h>
#include "header.h"
#define MAXLINE 256


int main(int argc, char * argv[])
{
    int shmid; 
    key_t key; 
    struct Memory *shm; 
    char wrLine[MAXLINE]; 
    int size;
    int tempInt1; 
    int tempInt2;

    key = ftok(".", 'x'); 
    if((shmid = shmget(key, sizeof(struct Memory), 0))<0){
        perror("shmget error \n"); 
        exit(1); 
    }
    shm = (struct Memory *)shmat(shmid, NULL, 0);
    if((long)shm == -1){
        perror("shmat error \n"); 
        exit(1); 
    }
    shm->gostop = GO; 
    shm->status = NOT_READY; 
    printf("starting process 1\n");
     printf("please print two integers \n");
    while ( (size = read(STDIN_FILENO, wrLine, MAXLINE)) > 0)
{
   
 if (sscanf(wrLine, "%d%d", &tempInt1, &tempInt2) == 2){
    printf("written to memory \n");
    shm->data.int1 = tempInt1;
    shm->data.int2 = tempInt2; 
    shm->status = FILLED; 
    while(shm->status != TAKEN)
    ;

printf("Data is taken by other process \n"); 
printf("please print two more integers \n");

 }else{
    printf("Invalid: please print two integers \n");
 }


}
shm->gostop = STOP; 
shmdt((void *) shm);   
return 0; 
}