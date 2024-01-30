#!/bin/bash
file="$1"
a=$(wc -l < "$file")
b=$(wc -w < "$file")
c=$(wc -c < "$file")
echo "Enter 1 for linecount, 2 for wordcount, 3 for charcount"
read option
case $option in
    1)
        echo "Line count: $a"
        ;;
    2)
        echo "Word count: $b"
        ;;
    3)
        echo "Character count: $c"
        ;;
    *)
        echo "Wrong value entered"
        ;;
esac

