#!/bin/bash

# Check if the password is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <password>"
    exit 1
fi

# Extract the ZIP file using 7zr
if 7zr x -p"$1" q.zip; then
    echo "Extraction successful."
else
    echo "Extraction failed."
    exit 1
fi

