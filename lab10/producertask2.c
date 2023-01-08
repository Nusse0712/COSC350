#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include<sys/shm.h>
#include<errno.h>
#include <time.h>
#include "header.h"

int main(int argc, char *argv[])
{
int shmid;
key_t key;
struct Memory *shm;

key = ftok(".", 'x'); //get key value
srand(time(NULL));
if ((shmid = shmget(key, sizeof(struct Memory), 0)) <0) //open shared memory
{
perror("shmget error \n");
exit (1);
}
shm = (struct Memory *) shmat(shmid, NULL, 0); //attach to shared memory
if ((long)shm == -1)
{
perror("shmat error \n");
exit (1);
}
shm->gostop = GO;
shm->status = NOT_READY;
shm->myData.count = 0; 
int Arrsize = 5;
while(1){
    for(int i =0; i < Arrsize; i++){
        shm->myData.arr[i] = (rand() % 9) + 1;
        shm->myData.count++; 
        
        
        if(shm->myData.count == Arrsize){
            shm->status=FILLED; 
            while(shm->status != TAKEN);

        }
       
         for(int j = 0; j < Arrsize; j++){
        printf("%d", shm->myData.arr[j]);
    }
         
   

printf("\n");
sleep(1);
    }

}
shm->gostop = STOP; 
shmdt((void *) shm); 
return 0; 
}