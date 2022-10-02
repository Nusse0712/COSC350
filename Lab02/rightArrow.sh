#!/bin/sh 

#asks the user for the length of the tail
echo "please enter the length of the tail"
read tail 

#asks the user for the length of the tail
echo "please enter an odd nuber for the length of the base" 
read base 

#checks to see if the value of the base is an odd number
a=`expr $base % 2`
#loop that keeps prompting the user for an odd number until one is given
until [ $a -eq 1 ];
do
	echo "please enter an odd number for the length of the base" 
	read base 
	a=`expr $base % 2`
done
rows=`expr $base / 2`
sum=`expr $tail + $base`
astericks=1
#printing first section of the arrow
for i in $(seq 1 $rows);
do
	#prints an amount of spaces based off the value of the baseLimit variable
	for j in $(seq 1 $tail);
	do
		echo -n "  "
	done
	#prints astericks based on the value of the variable astericks 
	for c in $(seq 1 $astericks);
	do
		echo -n " *"
	done
	echo
	#increments astericks by 2 for each loop 
	astericks=`expr $astericks + 2`

done
#printing the tail of the arrow
for j in $(seq 1 $sum);
do
	echo -n " *"
done
astericks=`expr $astericks - 2`
echo
#printing the last part of the arrow
for i in $(seq 1 $rows);
do
	#prints an amount of spaces based off the value of the baseLimit variable
	for j in $(seq 1 $tail);
	do
		echo -n "  "
	done
	#prints astericks based on the value of the astericks variable
	for c in $(seq 1 $astericks);
	do 
	  echo -n " *"
  done 
  echo
  #decrements the variable astericks by 2 for every loop 
  astericks=`expr $astericks - 2`
  done

