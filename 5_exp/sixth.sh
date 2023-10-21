#!/bin/bash
echo "Enter the number to print fibonacci series"
read num
i=0
num1=1
num2=0
sum=0
echo  "the fibonacci series is as follows:"
echo "the number is:"$num2
echo  "the number is:"$num1
while(($i < $num-2));do
   sum=$((num1 + num2))
   temp=$num1
   num1=$sum
   num2=$temp
   i=$((i+1))
   echo  "the number is:"$sum
done