#!/bin/bash
while((choice != -1));do
echo "ARITHEMATIC OPERATIONS"
echo "1.ADDITION"
echo "2.SUBTRACTION"
echo "3.MULTIPLICATION"
echo "4.DIVISION"
echo "5.MODULOS"
echo "enter your choice for performing operations"
read choice
if ((choice == 1));then
     echo "enter two number for operations"
     read num1
     read num2
     sum=$((num1+num2))
     echo "the addition result:$sum"
elif ((choice == 2));then
    echo "enter the two numbers for operations"
    read num1
    read num2
    sub=$((num1-num2))
    echo "the subtraction result:$sub"
elif ((choice == 3)); then
     echo "enter the two numbers for operations"
     read num1
     read num2
     mult=$((num1 * num2 ))
     echo "the multiplication is : $mult"
elif ((choice == 4)); then
    echo "enter the number for operations"
    read num1 
    read num2
    div=$((num1 / num2))
    echo "the division is:$div"
elif ((choice == 5)); then
    echo "enter the number for operations"
    read num1
    read num2
    mod=$((num1 % num2))
    echo "the modulos is:$mod"
elif ((choice == -1)); then
    echo "exiting ..."
else 
   echo "wrong choice"
fi 
done