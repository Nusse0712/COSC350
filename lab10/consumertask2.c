#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<errno.h>
#include<unistd.h>
#include "header.h"

int main(int argc, char *argv[])
{
int shmid, n, int1, int2;
key_t key;
struct Memory *shm;
key = ftok(".", 'x'); //get key value
// open existing shared memory
if ((shmid = shmget(key, sizeof(struct Memory), 0)) <0)
{
perror("shmget error \n");
exit (1);
}
//a pointer is attach to shared memory
shm = (struct Memory *) shmat(shmid, NULL, 0);
if ((long)shm == -1)
{
perror("shmat error \n");
exit (1);
}
int Arrsize = 5;
while (shm->gostop == GO)
{
    

for(int i =0; i < Arrsize; i++){
    while(shm->myData.count == 0){
        if(shm->gostop == STOP)
            break;
        
    }
    shm->myData.count--;
    shm->myData.arr[i] = 0;

    for(int j = 0; j < Arrsize; j++){
        printf("%d", shm->myData.arr[j]); 
    }
    printf("\n"); 
    shm->status=TAKEN;
    sleep(1); 

}

}
shmdt((void *) shm); //detach
return 0;
}
