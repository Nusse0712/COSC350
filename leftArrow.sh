#!/bin/sh

#asks the user for the tail size and the base of the arrow
echo "please enter the tail size"
read tail

echo "please enter an odd base base size"
read base

a=`expr $base % 2`
#loop that keeps prompting the user for an odd number until the user puts in an odd number
until [ $a -eq 1 ];
do
	        echo "please enter an odd number"
		read base
                a=`expr $baseSize % 2`
done

rows=`expr $base / 2`
astericks=1
spaces=$base
baseLimit=`expr $base - 2`
sum=`expr $base + $tail`
#printing the first section of the arrow
for i in $(seq 1 $rows);
do
	#prints out the number of spaces depending on the number of the baseLimit
	for j in $(seq 1 $baseLimit);		
	do
		echo -n "  "
	done
	#prints out the number of astericks based off of the value of the astericks variable
	for c in $(seq 1 $astericks);
	do
		echo -n " *"
	done
echo
#increments the astericks by two and decrements the amount of spaces by 2
astericks=`expr $astericks + 2`
baseLimit=`expr $baseLimit - 2`
done
#prints the tail of the arrow
for j in $(seq 1 $sum)
do 
	echo -n " *"
done
echo

astericks=`expr $astericks - 2`
baseLimit=`expr $baseLimit + 2`
#printing the last part of the arrow
for i in $(seq 1 $rows);
do
	#prints out the number of spaces depending on the value of the baseLimit variable
	for j in $(seq 1 $baseLimit);
	do
		echo -n "  "
	done
	#prints out astericks based off of the value of the astericks variable
	for c in $(seq 1 $astericks);
	do 
		echo -n " *"
	done
	echo
#increments the spaces by 2 and decrements the astericks by 2
astericks=`expr $astericks - 2`
baseLimit=`expr $baseLimit + 2`
		
done
