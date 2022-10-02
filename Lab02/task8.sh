#!/bin/sh

#if there are no parameters passed, then the program will give the user a message and exit
if [ $# -eq 0 ] 
then 
	echo "no argument detected"
	exit 0; 
fi 
#if there is more than one passed, then the program will give the user a message and exit
if [ $# -gt 1 ]
then 
	echo "more than one argument"
	exit 0; 
fi 
#variable num is the value of the parameter passed
num=$1

#sum variable to keep track of the sum of the number
sum=0
#loop to get the sum
while [ $num -gt 0 ];
do
       #the variable temp is intialized by finding the modulus of the number by 10
       temp=`expr $num % 10`
       #temp is subtracted from num in order to get the next number
       num=`expr $num - $temp`
       #num is then divided by 10 to get the next number posistion 
       num=`expr $num / 10`
       #temp is added to the current sum 
       sum=`expr $sum + $temp`
done
#printing of the sum of all numbers
echo $sum
exit 0;
	
