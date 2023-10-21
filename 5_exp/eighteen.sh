#!/bin/bash

echo "Enter the letter to search for:"
read letter

echo "List of files starting with the letter $letter:"

# Iterate through files in the current directory
for file in "$letter"*
do
    if [ -f "$file" ]; then
        echo "$file"
    fi
done

