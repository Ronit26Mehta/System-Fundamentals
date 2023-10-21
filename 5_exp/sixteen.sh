#!/bin/bash
echo "Enter file name:"
read file
line_count=$(wc -l < "$file")
character_count=$(wc -c < "$file")
word_count=$(wc -w < "$file")
echo "Enter search pattern:"
read pattern
matched_line_count=$(grep -o "$pattern"  "$file" | wc -l)
matched_word_count=$(grep -o "$pattern"  "$file" | wc -c)
matched_character_count=$(grep -o "$pattern"  "$file" | wc -w)
echo "the total count for lines:$line_count"
echo "the matched count for lines:$matched_line_count"
echo "the total count for characters:$character_count"
echo "the matched count for characters:$matched_character_count"
echo "the total count for word:$word_count"
echo "the matched count for word:$matched_word_count"