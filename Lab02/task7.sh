#!/bin/sh

#asks the user for a number
echo "please enter a number"
read num

#initializing a factorial variable that keeps track of the profit
factorial=1

#loop that goes through the factorial
while [ $num -gt 1 ];
do 
	#factorial is calcualted by multiplying the factorial number by the current number
	factorial=`expr $factorial \* $num`
	#number is decremented by 1 to simulate factorial 
	num=`expr $num - 1`
done
#prints the factorial number
echo $factorial 

