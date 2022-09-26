#!/bin/sh 

#asks the user for the length of the tail
echo "please enter the length of the tail"
read tail 

#asks the user for the length of the tail
echo "please enter an odd nuber for the length of the base" 
read base 

#checks to see if the value of the base is an odd number
a=`expr $base % 2`

until [ $a -eq 1 ];
do
	echo "please enter an odd number for the length of the base" 
	read base 
	a=`expr $base % 2`
done
rows=`expr $base / 2`
baseLimit=`expr $base - 1`
sum=`expr $tail + $base`
astericks=1
for i in $(seq 1 $rows);
do
	for j in $(seq 1 $baseLimit);
	do
		echo -n "  "
	done
	for c in $(seq 1 $astericks);
	do
		echo -n " *"
	done
	echo
	astericks=`expr $astericks + 2`

done
for j in $(seq 1 $sum);
do
	echo -n " *"
done
astericks=`expr $astericks - 2`
echo
for i in $(seq 1 $rows);
do
	for j in $(seq 1 $baseLimit);
	do
		echo -n "  "
	done
	for c in $(seq 1 $astericks);
	do 
	  echo -n " *"
  done 
  echo
  astericks=`expr $astericks - 2`
  done

