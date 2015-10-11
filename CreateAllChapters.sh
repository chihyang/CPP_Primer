#!/bin/sh
# Create chapter folder.
for i in {1..9} 
do
	o="chap0$i" # No space between expressions and '=' 
	if [ -d $o ];then
		echo "$o has already exists" | sed 's/\/\//\//'
	else
		mkdir $o
		echo "$o is created" | sed 's/\/\//\//'
	fi
done
for i in {10..19} 
do
	o="chap$i" # No space between expressions and '=' 
	if [ -d $o ];then
		echo "$o has already exists" | sed 's/\/\//\//'
	else
		mkdir $o
		echo "$o is created" | sed 's/\/\//\//'
	fi
done
