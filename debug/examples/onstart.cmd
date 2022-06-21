#!/bin/sh
PID=$1
PIPID=$2
PROG=`basename $3`
echo "###" $0 "### "${PROG} ${PID} ${PIPID}
pips -f ${PID} # strace, ltrace, pip-gdb, ...
kill -CONT ${PID} 
