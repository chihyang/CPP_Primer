# Add prefix 0 before exercises' chapter number.
for file in `ls`  
do
    newfile =`echo $i | sed 's/\(^Exer\)\([1-9]\)/\10\2/'`
    mv $file $newfile  
done