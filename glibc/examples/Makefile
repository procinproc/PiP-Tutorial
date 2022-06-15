
include ../../rules.mk

all: interp.out maps.out const-dest.out

interp.out: interp.sh ../../example.sh Makefile
	../../example.sh < interp.sh > interp.out

maps.out: maps.c maps.sh Makefile
	pipcc maps.c -o a.out
	pip-exec -n 2 ./a.out > maps.exout
	./maps.sh maps.exout > maps.out

const-dest.out: const-dest.c const-dest.sh ../../example.sh
	pipcc const-dest.c -o const-dest
	../../example.sh < ./const-dest.sh > const-dest.out

clean-hook:
	$(RM) a.out
