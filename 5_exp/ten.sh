#!/bin/bash
echo "Enter the number to find the sum of digits"
read number
temp=$number
sum=0
while [ $temp -ne 0 ]; do
   sum=$((sum + temp % 10))
   temp=$((temp / 10))
done
echo "the sum of digit for the $number is $sum"