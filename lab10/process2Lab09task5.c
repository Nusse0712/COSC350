#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h> 
#include <unistd.h>
#include "header.h"
#define MAXLINE 256

int main(int argc, char *argv[]){
    int shmid, n, int1, int2; 
    key_t key; 
    struct Memory *shm; 
    key = ftok(".",'x'); 

    if((shmid = shmget(key, sizeof(struct Memory), 0))<0){

            perror("shmget error \n"); 
            exit(0);
    }
    shm = (struct Memory *) shmat(shmid, NULL, 0); 
    if((long)shm == -1){
        perror("shmget error \n"); 
        exit(1); 
    }

    while(shm->gostop == GO){
        while(shm->status != FILLED){
            
            if(shm->gostop==STOP){
                break;
            }
            ;
        }
        printf("the sum of ints %d and %d is %d \n",shm->data.int1,shm->data.int2,shm->data.int1+shm->data.int2);
        shm->status = TAKEN;
    }
    shmdt((void *) shm);
    return 0;
    
}