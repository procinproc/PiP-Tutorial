
include ../../rules.mk

all: src-build.out

src-build.out: src-build.sh
	$(RM) -r PiP-build
	$(RM) src-build.log src-build.o
	mkdir PiP-build
	./example.sh < src-build.sh > script
	bash script > src-build.o
	wd=`realpath .`/PiP-build; sed -E "s.$$wd.\<PIPTOP\>.g" < src-build.o > $@
