#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h> 
#include <unistd.h>
#define MAXLINE 256

struct my_msgbuf{
    long mType; 
    int int1; 
    int int2; 
}; 

int main(void){
struct my_msgbuf buf; 
int msqid;
key_t key;
char wrLine[MAXLINE]; 
int size;
int tempInt1,tempInt2;
/*create a key for create message queue */
if ((key = ftok("msgQsnd.c", 'B')) == -1) {
perror("ftok error");
exit(1);
}

if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
perror("msgget error");
exit(1);
} 
printf("Enter two integers, ^D to quit:\n");
buf.mType = 1;
while ( (size = read(STDIN_FILENO, wrLine, MAXLINE)) > 0)
{
   
 if (sscanf(wrLine, "%d%d", &tempInt1, &tempInt2) == 2){
    buf.int1 = tempInt1;
    buf.int2 = tempInt2; 
   if (msgsnd(msqid, (struct msgbuf *)&buf, sizeof(buf), 0) == -1){
       perror("msgsnd error");
   }
printf("please print two more integers \n");

 }else{
    printf("Invalid: please print two integers \n");
 }
}

if (msgctl(msqid, IPC_RMID, NULL) == -1) {
perror("msgctl error");
exit(1);
}
exit(0);




}