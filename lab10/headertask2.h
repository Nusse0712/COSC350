#include <stdlib.h>
#define NOT_READY -1
#define FILLED 0
#define TAKEN  1
#define GO     2
#define STOP   3

struct data{
    int arr[5];
    int count;
}; 
struct Memory{
    int status; 
    int gostop; 
    struct data myData; 
    
};