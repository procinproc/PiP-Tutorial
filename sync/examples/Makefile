
include ../../rules.mk

all: barrier.out pthread-barrier.out pthread-mutex.out

barrier.out: barrier.c barrier.sh Makefile ../../example.sh 
	pipcc barrier.c -o barrier
	../../example.sh < barrier.sh > barrier.out

pthread-barrier.out: pthread-barrier.c pthread-barrier.sh Makefile ../../example.sh
	pipcc pthread-barrier.c -o pthread-barrier
	../../example.sh < pthread-barrier.sh > pthread-barrier.out

pthread-mutex.out: pthread-mutex.c pthread-mutex.sh Makefile ../../example.sh
	pipcc pthread-mutex.c -o pthread-mutex
	../../example.sh < pthread-mutex.sh > pthread-mutex.out

clean-hook:
	$(RM) barrier pthread-barrier
