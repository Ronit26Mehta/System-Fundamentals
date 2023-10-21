#1bin/bash
echo "enter name of file to copy the contents from file:"
read file1
echo "enter name of the file where the contents would be copied:"
read file2
cp $file1 $file2
echo "the contents of the file $file1:"
cat $file1 | head -1
echo  "the contents of the file $file2:"
cat $file2 | head -1