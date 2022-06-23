#!/bin/sh

while read line; do
    echo '$' $line;
    sh -c "$line" 2>&1;
done
echo '$';

