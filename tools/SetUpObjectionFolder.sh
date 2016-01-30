#!/bin/sh
# Add object folder under each chapter folder.
for folder in `ls -F | grep "chap[0-9]"`  
do
	o="$folder/obj" # No space between expressions and '=' 
	if [ -d $o ];then # -d is used to judge if $o is a directory
		echo "$o already exists" | sed 's/\/\//\//'
	else
		mkdir $folder/obj
		echo "$o is created" | sed 's/\/\//\//'
	fi
done
