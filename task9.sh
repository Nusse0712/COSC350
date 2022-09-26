#!/bin/sh 

#asks the user for the name of the directory
echo "Please enter the name of the directory" 
read directory
#if statement that checks if the name given is a directory, if not the program exits 
if [ -d $directory ]
then 
	echo "directory found!"
else 
	echo "directory not found!"
	exit 1;
fi 

tries=0
#gives the user three tries to get the name of the file
while [ $tries -lt 3 ];
do 
#asks for a file, if the file is found then its breaks the loop	
	echo "please write the name of a file down"
	read file
	if [ -r $file ]    
	then
		break
	fi 
#increments tries by 1 through each loop 
tries=`expr $tries + 1`
done
#if the file is readible, it allows the user to search a word
#if the file is not readible, it will tell the user too many tries
if [ -r $file ]
then
#lets the user look for a word in the file
echo "please name the word you are trying to find"
read word

#the variable wordFound is initalized with the grep filter using the -c option
#this counts the number of times the word is in the file
wordFound=$(grep -c $word $file)
#if the wordFound is greater than zero, that means that the word appears in the file, 
#printing the message "word Found", if wordFound is equal to zero then the word is not found
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
