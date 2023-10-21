#!/bin/bash
echo enter directory name
read d
mkdir $d
echo enter file number
read n
for((i=0;i<n;i++))
do 
echo enter file name
read f
cp $f $d
done