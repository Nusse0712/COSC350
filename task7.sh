#!/bin/sh

echo "please enter a number"
read num

factorial=1

while [ $num -gt 1 ];
do 
	factorial=`expr $factorial \* $num`
	num=`expr $num - 1`
done
echo $factorial 

