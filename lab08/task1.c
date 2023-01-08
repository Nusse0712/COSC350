#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 
//run with gcc -pthread -o task1 task1.c

//prototypes of the various thread functions
void *findFactorial( void *ptr); 
void *findSum(void *ptr);
int str_to_int(char * ar);


int main(int argc, char *argv[]){
//checking the amount of arguments
if(argc != 2){
    printf("ARGUMENT ERROR"); 
    exit(0);
}
//declaring two pthreads 
pthread_t thread1, thread2; 

int rc1, rc2; 

char * args =  argv[1];
//creating first pthread to find the factorial
if((rc1 = pthread_create(&thread1, NULL, findFactorial, (void*)args ))!=0){
    printf("Error; return code from the pthread_create() is %d \n ",rc1);
    exit(0);
}

//creating the second pthread to find the sum
if((rc2 = pthread_create(&thread2, NULL, findSum, (void*)args ))!=0){
    printf("Error; return code from the pthread_create() is %d \n ",rc2);
    exit(0);
}
//pthread join to wait until the thread terminates 
pthread_join(thread1, NULL);
pthread_join(thread2,NULL);

exit(0); 
}
//function str_to_int turns a string to an integer 
int str_to_int(char * ar){
int num = 0; 

for(int i = 0; ar[i] != '\0'; i++){
    if(ar[i] > '9' || ar[i] < '0'){
       return 0;
    }
    num = num*10 + ar[i] - '0';
}

    return num;
}

//thread function that finds the factorial of the ptr being passed in
void *findFactorial(void *ptr){
    char * c = (char *) ptr;
    int num = str_to_int(c); 
    int factorial = 1;
    for(int i = 1; i <= num; i++){
        factorial = factorial * i;
    }
    printf("Factorial is: %d \n",factorial); 

    pthread_exit(NULL);
}
//thread function that finds the sum of the ptr being passed in
void *findSum(void * ptr){
    char * c = (char *) ptr;
    int num = str_to_int(c); 
    int sum = 0; 

    for(int i = 1; i <= num; i++){
        sum = sum + i;
    }
    printf("Sum is: %d \n",sum);

    pthread_exit(NULL);
}