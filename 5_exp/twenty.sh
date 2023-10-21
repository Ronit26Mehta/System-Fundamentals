#!/bin/bash

echo "Enter the file name:"
read file

echo "Enter the pattern to replace:"
read pattern

echo "Enter the replacement:"
read replacement

echo "Enter the Nth occurrence to replace:"
read occurrence

awk -v pat="$pattern" -v rep="$replacement" -v n="$occurrence" '{ 
    while (match($0, pat)) {
        if (++count == n) {
            sub(pat, rep);
            break;
        }
        else {
            pre = pre substr($0, 1, RSTART+RLENGTH-1);
            $0 = substr($0, RSTART+RLENGTH);
        }
    }
    print pre $0;
}' "$file" > tmpfile && mv tmpfile "$file"

echo "Pattern replaced successfully."
