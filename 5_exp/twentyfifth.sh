#!/bin/bash
echo "enter the number to check even or odd"
read number
calc=$((number % 2))
if [ $calc -eq 0 ]; then
    echo "$number is even"
else
     echo "$number is odd"
fi