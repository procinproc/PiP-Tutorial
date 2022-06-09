#!/bin/sh -x

TUTDIR=`realpath .`
PIPCC=`pipcc --where`
PIPBINDIR=`dirname $PIPCC`
PIPDIR=`dirname $PIPBINDIR`
PIPLIBDIR="$PIPDIR/lib"
GLIBCDIR=`$PIPLIBDIR/libpip.so --glibc`

pip-exec -n 2 ./maps > maps.exout
sed -e "s!$PIPDIR!/PiP/bin/!g" \
    -e "s!$PIPLIBDIR!/PiP/lib/!g" \
    -e "s!$TUTDIR!/PiP/example/!g" \
    -e "s!$GLIBCDIR!/lib64/!g" \
    -e "s!                 !!g" \
    maps.exout | grep 'r-xp' >  maps.out
