#!/bin/bash
echo Enter number1 ,number2,number3
read number1
read number2
read number3
if((number1>number2 && number1>number3));then
     echo "$number1 is greater"
elif((number2>number1 && number2>number3));then
     echo "$number2 is greater"
elif((number3>number1 && number3>number2));then
     echo "$number3 is greater"
else
   echo "all numbers are equal"
fi