#!/bin/sh
# Add prefix 0 before exercises' chapter number.
for folder in `ls -F | grep '/'`
do
	for file in `ls $folder | grep '.cpp'`
	do
		newfile=`echo $file | sed 's/\(^Exer\)\([1-9]$\)/\10\2/'`
		if [ "$folder$file"x != "$folder$newfile"x ]
		then
			mv $folder$file $folder$newfile
		else
			echo "obj folder has existed"
		fi
	done
done
