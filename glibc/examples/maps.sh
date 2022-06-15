#!/bin/sh -x

TUTDIR=`realpath .`
PIPCC=`pipcc --where`
PIPBINDIR=`dirname $PIPCC`
PIPDIR=`dirname $PIPBINDIR`
PIPLIBDIR="$PIPDIR/lib"
GLIBCDIR=`$PIPLIBDIR/libpip.so --glibc`

sed -e "s!$PIPBINDIR!/PiP/bin!g" \
    -e "s!$PIPLIBDIR!/PiP/lib!g" \
    -e "s!$TUTDIR!/PiP/example!g" \
    -e "s!$GLIBCDIR!/lib64!g" \
    -e "s!                !!g" \
    $1
    # $1 | grep 'r-xp'
