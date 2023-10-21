#!/bin/bash
echo "enter the number to check for prime:"
read number
i=2
flag=1
if(($number<=1 ));then
    echo "$number is not a prime"
    exit
fi
while((number>i));do
num=$((number % i))
 if (($num == 0));then
   flag=0
   break
   fi
   i=$((i+1)) 
done
if(($flag == 0));then
    echo "$number is not a prime"
else
   echo "$number is a prime"
fi