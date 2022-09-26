#!/bin/sh


if [ $# -eq 0 ] 
then 
	echo "no argument detected"
	exit 0; 
fi 
if [ $# -gt 1 ]
then 
	echo "more than one argument"
	exit 0; 
fi 
num=$1

sum=0
while [ $num -gt 0 ];
do
       temp=`expr $num % 10`
       num=`expr $num / 10`
       sum=`expr $sum + $temp`
done
echo $sum
exit 0;
	
