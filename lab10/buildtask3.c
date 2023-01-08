#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "header.h"
union semun arg;
int main(int argc, char *argv[])
{
int shmid;
key_t key;
int semid;
struct Memory *shm;
key = ftok(".", 'x'); //create a key value
//create a shared memory
if ((shmid = shmget(key, sizeof(struct Memory), IPC_CREAT | 0666)) <0)
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
if ((semid = semget(key, 3, 0666 | IPC_CREAT)) == -1)
{
perror("semget Error");
exit(1);
}

arg.val = 1;

if (semctl(semid, MUTEX, SETVAL, arg) == -1)
{
perror("semctl");
exit(1);
}
arg.val = 0;

if (semctl(semid, FULL, SETVAL, arg) == -1)
{
perror("semctl");
exit(1);
}
arg.val = N;

if (semctl(semid, EMPTY, SETVAL, arg) == -1)
{
perror("semctl");
exit(1);
}
for(int i = 0; i < 5; i++){
    shm->arr[i]=0;
}

shm->status = NOT_READY;
shm->gostop = GO;
return 0;
}