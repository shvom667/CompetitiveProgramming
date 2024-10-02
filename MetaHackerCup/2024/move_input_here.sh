#!/bin/bash

path="$HOME/Downloads"
name=$(find "$path" -maxdepth 1 -type f -printf "%T+ %p\n" | sort | tail -n 1 | awk '{print $2}')
bname=$(basename "$name")

# Echo the basename correctly
echo "$bname"

ext="${bname##*.}"

echo "$ext"

if [ "$ext" == "txt" ]; then
    mv "$name" "$path/q.in"
elif [ "$ext" == "zip" ]; then
    mv "$name" "$path/q.zip"
else 
    echo "Unknown extension"
fi

