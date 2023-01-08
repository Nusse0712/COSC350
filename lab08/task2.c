#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 

float * numArray;
int  size; 
//prototypes for the thread functions 
//run with gcc -pthread -o task2 task2.c

void *getUserInput(void * ptr);
void *calculateAverage_and_Median(void * ptr); 
void *findMin_and_Max(void * ptr);
void *setToZero(void * ptr);



int main(int argc, char *argv[]){
//declaring four threads 
pthread_t thread1, thread2, thread3,thread4;
int rc1 ,rc2,rc3,rc4,t; 
//asking the user for the scores to be calculated
printf("How many scores to calculate? \n");
scanf("%d", &size); 
//creating a dynamic array based on the size put in the user 
numArray = (float*)malloc(size * sizeof(float));
//creating the first pthread to get the scores 
if((rc1=pthread_create(&thread1,NULL, getUserInput,NULL))!= 0){
    printf("Error; return code from the pthread_create() is %d \n ",rc1);
    exit(0);
}
//suspending the rest of the program until thread1 ends
pthread_join(thread1, NULL);
//creating the second pthread to find the average and the median of the array
if((rc2=pthread_create(&thread2,NULL, calculateAverage_and_Median,NULL))!= 0){
    printf("Error; return code from the pthread_create() is %d \n ",rc2);
    exit(0);
}
//creating the third pthread to find the maximum and minimum of the dataset
if((rc3=pthread_create(&thread3,NULL, findMin_and_Max,NULL))!= 0){
    printf("Error; return code from the pthread_create() is %d \n ",rc3);
    exit(0);
}
//pthread join function will suspend the program until pthread2 and pthread3
pthread_join(thread2,NULL);
pthread_join(thread3,NULL);
//creating pthread4 to set all the elements of the array to zero 
if((rc4=pthread_create(&thread4,NULL, setToZero,NULL))!= 0){
    printf("Error; return code from the pthread_create() is %d \n ",rc4);
    exit(0);
}

pthread_join(thread4,NULL);





exit(0); 
}

//function that gets the user input 
void* getUserInput(void * ptr){

    int num; 
    for(int i = 0; i < size; i++){
        printf("enter test score #%d \n",i+1);
        scanf("%f", &numArray[i]);
    }

    float temp; 
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(numArray[j] > numArray[j+1]){
                temp = numArray[j]; 
                numArray[j] = numArray[j+1];
                numArray[j+1] = temp;
            }
        }
    }

    printf("The sorted list of test scores \n");
    for(int i = 0; i < size; i++){
        printf("score #%d :%f \n",i+1,numArray[i]);
    }
    pthread_exit(NULL);
}
//function that calculates the average and the median 
void *calculateAverage_and_Median(void * ptr){
    float average = 0.0; 

    for(int i = 0; i < size; i++){
        average = average + (float)numArray[i]; 
    }
    average = average/size; 

    printf("The average for the test scores is: %f \n",average);
    float median;
    if(size % 2 == 0){
    median = (numArray[size/2] + numArray[(size/2)-1])/2.0;
    }else{
    median = numArray[size/2];
    }

    printf("The median for this list is %f \n",median);

     pthread_exit(NULL);
}

//find the minimum and maximum value of the array
void *findMin_and_Max(void * ptr){

printf("The minimum value is: %f \n",numArray[0]); 
printf("The maximum value is: %f \n",numArray[size-1]);
    pthread_exit(NULL); 
}

//setting all the scores to zero and freeing the array
void * setToZero(void * ptr){
printf("Setting all scores to zero \n");

for(int i = 0; i < size; i++){
     numArray[i] = 0.0;
     printf("score #%d: %f \n",i+1,numArray[i]);
}
    printf("freeing the test score Array \n");
    free(numArray);
    pthread_exit(NULL); 
}




