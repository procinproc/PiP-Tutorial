
include ../../rules.mk

all: hook.out

hook.out: hook.c hook.sh ../../example.sh Makefile
	pipcc hook.c -o hook
	../../example.sh < hook.sh > hook.out

clean-hook:
	$(RM) hook
