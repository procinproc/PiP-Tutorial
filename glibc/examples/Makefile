
include ../../rules.mk

all: interp.out maps.out hello.out

interp.out: interp.sh ../../example.sh Makefile
	../../example.sh < interp.sh > interp.out

maps.out: maps.c maps.sh Makefile
	pipcc maps.c -o a.out
	pip-exec -n 2 ./a.out > maps.exout
	./maps.sh maps.exout > maps.out

hello.out: hello.cpp hello.sh ../../example.sh Makefile
	pipcc hello.cpp -o hello
	../../example.sh < hello.sh > hello.out

clean-hook:
	$(RM) hello
