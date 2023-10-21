#!/bin/bash
echo "enter the number for the table display"
read number
echo "enter the table range"
read range
echo "the table for the given $number:"
for((i=0;i<=range;i++));do
echo "$number *  $i = $(( number * i ))"
done