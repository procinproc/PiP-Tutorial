#!/bin/sh

while read line; do
    echo '$' $line;
    sh -c "$line";
done

