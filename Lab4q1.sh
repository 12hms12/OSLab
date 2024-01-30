#!/bin/bash
file1=$1
copyFile="${file1}_copy"
cp "$file1" "copyFile"
echo "$file1 has been successfully copied: $copyFile"
