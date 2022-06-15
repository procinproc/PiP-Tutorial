
include ../../rules.mk

all: pip-check.out pip-exec.out libpip.out

pip-check.out: pip-check.sh pip.c ../../example.sh
	../../example.sh < pip-check.sh > pip-check.out

pip-exec.out: pip-exec.sh prog.c ../../example.sh
	../../example.sh < pip-exec.sh > pip-exec.out

libpip.out: libpip.sh ../../example.sh
	export PIPLIBDIR=$$(dirname $$(pipcc --where))/../lib; \
	../../example.sh < libpip.sh > libpip.out

clean-hook:
	$(RM) pip pip-task pip-root a.out b.out c.out
