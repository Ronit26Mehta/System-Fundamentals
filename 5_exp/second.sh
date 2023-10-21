#!bin/bash
echo Enter file name:
read f
echo no. of lines:
wc -l < $f
echo no. of characters:
wc -c < $f 
echo no. of words:
wc -w < $f 
 