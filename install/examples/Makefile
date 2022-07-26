
include ../../rules.mk

all: src-build.out

src-build.out: src-build.sh
	$(RM) -r PiP-build
	$(RM) src-build.log
	mkdir PiP-build
	./example.sh < src-build.sh > script
	bash script > $@ 2>&1
