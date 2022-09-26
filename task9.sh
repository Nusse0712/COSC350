#!/bin/sh 


echo "Please enter the name of the directory" 
read directory

if [ -d $directory ]
then 
	echo "directory found!"
else 
	echo "directory not found!"
	exit 1;
fi 

tries=0

while [ $tries -lt 3 ];
do 
	echo "please write the name of a file down"
	read file
	if [ -r $file ]    
	then
		break
	fi 
tries=`expr $tries + 1`
done

if [ -r $file ]
then
echo "please name the word you are trying to find"
read word

wordFound=$(grep -c $word $file)
if [ $wordFound -gt 0 ]
then 
	echo "word found"
else 
	echo "word not found"
fi
else
	echo "Too many tries attempted"
fi
exit 0;
