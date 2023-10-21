echo "Listing files in directory"
ls
echo -e "\nDescription of each file:"

for file in *; do
    if [ -f "$file" ]; then
        echo -n "File: $file | "
        echo -n "Type: $(file -b "$file") | "
        echo "Size: $(du -h "$file" | cut -f1)"
    fi
done
