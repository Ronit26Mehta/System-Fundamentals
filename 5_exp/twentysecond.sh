#!/bin/bash
echo "enter the value to get its power"
read value
echo "enter the power:"
read power
answer=$((value**power))
echo "$value raise to the $power:$answer"