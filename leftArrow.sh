#!/bin/sh

echo "please enter the tail size"
read tail

echo "please enter an odd base base size"
read base

a=`expr $base % 2`

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
baseLimit=`expr $baseLimit - 2`
done

for j in $(seq 1 $sum)
do 
	echo -n " *"
done
echo

astericks=`expr $astericks - 2`
baseLimit=`expr $baseLimit + 2`
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
baseLimit=`expr $baseLimit + 2`
		
done
