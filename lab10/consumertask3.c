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
int main(int argc, char *argv[])
{
int shmid, n, int1, int2;
key_t key;
int semid;
int item;
int location;
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

if ((semid = semget(key, 3, 0)) == -1) {
perror("semget");
exit(1);
}
while(1){
down(semid,FULL); 
down(semid,MUTEX); 
item = 0; 
up(semid, MUTEX); 
up(semid, EMPTY);
location = semctl(semid, FULL, GETVAL);

shm->arr[location] = item;
for(int i = 0; i < 5; i++){
    printf("%d ",shm->arr[i]);
}
printf("\n");
sleep(1);
}

shmdt((void *) shm); //detach
return 0;
}