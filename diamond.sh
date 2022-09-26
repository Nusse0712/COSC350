#!/bin/sh 

#asks the user for an odd number greather than three
echo "please enter an odd number greater than 3 to create the diamond"
read diamondSize

a=`expr $diamondSize % 2`
#keeps prompting the user for an odd number greater than 3 until the user puts it in
until [ $a -eq 1 ] && [ $diamondSize -gt 3 ];
do
	echo "please enter an odd number greater than 3"
	read diamondSize
	a=`expr $diamondSize % 2`
done

rows=`expr $diamondSize / 2`
astericks=1
spaces=$diamondSize
#for loop to print out the first part of the diamond
for i in $(seq 1 $rows); 
do 
	for j in $(seq 1 $spaces);
	do
		echo -n "  "
	done
	for c in $(seq 1 $astericks);
	do 
		echo -n "* "

	done
echo
#updating the astericks and spaces to get a diamond shape
astericks=`expr $astericks + 2`
spaces=`expr $spaces - 1`
done
#printing the middle of the diamond
for i in $(seq 1 $spaces);
do 
	echo -n "  "
done
for i in $(seq 1 $diamondSize);
do
	echo -n "* "
done
echo
#printing the second part of the diamond
for i in $(seq 1 $rows);
do
	astericks=`expr $astericks - 2`
	spaces=`expr $spaces + 1`
	for j in $(seq 1 $spaces);
	do
		echo -n "  "
	done
	for c in $(seq 1 $astericks);
	do
		echo -n "* "
	done
echo 
done
