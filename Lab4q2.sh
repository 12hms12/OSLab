#!/bin/bash
for file in "$@"; do
	rm -i "$file"
done
echo "Files have been deleted"
