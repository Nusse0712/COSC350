#include <stdio.h>
#include <unistd.h>
/*
Lab #3 
Task 1
Cole Nussear

copies the content of any readable file to a file
without open input file

runs by cat foo | ./task1 > clone
*/
int main()
{

    char b[1]; 
    int nread; 
    while((nread = read(0, b, 1)) > 0){
        write(1, b, nread);
    }
    return 0; 
}