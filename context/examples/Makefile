
include ../../rules.mk

all: context.out

context.out: context.c context.sh ../../example.sh Makefile
	pipcc context.c -o context
	../../example.sh < context.sh > context.out

clean-hook:
	$(RM) context

