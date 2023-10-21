#!/bin/bash
echo enter a number to find factorial
read num
fact=1
for ((i=2; i<=num; i++)); do  
    fact=$((fact * i)) 
done
echo the factorial of $num is $fact