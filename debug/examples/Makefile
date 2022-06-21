
include ../../rules.mk

all: stop-on-start.out

stop-on-start.out: stop-on-start.sh onstart.cmd Makefile ../../example.sh
	PIP_STOP_ON_START=onstart.cmd@2 \
	../../example.sh < ./stop-on-start.sh > stop-on-start.out

clean-hook:
	$(RM) hello
