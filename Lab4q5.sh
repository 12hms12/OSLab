#!/bin/bash

file="$1"

echo "Enter Pattern: "
read pattern

echo "Enter 1 to search pattern, 2 to delete pattern, 3 to exit shell script: "
read option

case $option in
    1)
        grep "$pattern" "$file"
        echo "Pattern found"
        ;;
    2)
        sed -i "/$pattern/d" "$file"
        echo "Pattern deleted"
        ;;
    3)
        echo "Exiting..."
        exit 0
        ;;
    *)
        echo "Invalid option. Exiting..."
        exit 1
        ;;
esac

