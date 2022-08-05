
include ../../rules.mk

all: src-build.mout

src-build.mout: src-build.sh Makefile
	$(RM) -r PiP-build
	$(RM) src-build.log src-build.o
	mkdir PiP-build
	./example.sh < src-build.sh > script
	bash script > src-build.out
	wd=`realpath .`/PiP-build; sed -E "s.$$wd.\<PIPTOP\>.g" < src-build.out > $@
	$(RM) -r PiP-build
	$(RM) src-build.log src-build.o

clean-hook:
	$(RM) -r PiP-build
	$(RM) src-build.log src-build.o
