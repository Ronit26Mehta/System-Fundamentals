#!/bin/bash
echo "enter celcius to convert to fahrenint:"
read c
convert=$(($c * 2))
echo "the converted value is $convert"