#!/bin/sh
# Add object folder under every chapter folder.
for folder in `ls -F | grep "chap[0-9]"`  
do
	o="$folder/obj" # No space between expressions and '=' 
	if [ -d $o ];then
		echo "$o has already exists" | sed 's/\/\//\//'
	else
		mkdir $folder/obj
		echo "$o is created" | sed 's/\/\//\//'
	fi
done
