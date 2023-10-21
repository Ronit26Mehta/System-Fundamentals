#!/bin/bash
echo "enter the year to check for leap"
read year
calc=$((year%4))
if [ $calc -eq 0 ]; then
     echo "$year is a leap"
else
   echo "$year is not a leap"
fi