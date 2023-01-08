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

int main(void)
{
struct my_msgbuf buf;
int msqid;
key_t key;

if ((key = ftok("msgQsnd.c", 'B')) == -1) {
perror("ftok error");
exit(1);
}
if ((msqid = msgget(key, 0644)) == -1) {
perror("msgget error");
exit(1);
}
printf(" ready to receive messages,.\n");
for(;;) {
/* get each message from the message queue */
if (msgrcv(msqid, (struct msgbuf *)&buf, sizeof(buf), 0, 0) == -1) {
perror("msgrcv error");
exit(1);
}

printf("The values %d and %d added up are %d \n",buf.int1,buf.int2,buf.int1+buf.int2);
}


return 0;
}
