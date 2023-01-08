#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include<sys/shm.h>
#include<errno.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "header.h"
void down(int semid, int index)
{
struct sembuf buf = {index, -1, 0};
semop(semid, &buf, 1);
}
void up(int semid, int index)
{
struct sembuf buf = {index, 1, 0};
semop(semid, &buf, 1);
}

int main(void){
    int shmid;
key_t key;
struct Memory *shm;
int semid;
int location;
int item;
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

if ((semid = semget(key, 3, 0)) == -1) {
perror("semget");
exit(1);
}

while (1) {


item=  (rand() % 9) + 1;
down(semid,EMPTY); 
down(semid,MUTEX);
location  = semctl(semid, FULL, GETVAL); 

shm->arr[location] = item; 
for(int i =0; i < 5; i++){
    printf("%d ",shm->arr[i]);
}
printf("\n");
up(semid,MUTEX);
up(semid, FULL);
sleep(1);

}
shm->gostop = STOP; 
shmdt((void *) shm); 
return 0;
}