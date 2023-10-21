#!bin/bash
echo "enter the number to find its reverse"
read number
temp=$number
reverse=0
while [ $temp -ne 0 ]; do
reverse=$((reverse * 10 + temp % 10))
temp=$((temp / 10))
done
echo "the $number reverse is $reverse"