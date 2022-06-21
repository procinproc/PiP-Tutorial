
include ../../rules.mk

all: hello.out hello-var.out hello-var-omp.out export-import.out

hello.out: hello.c hello.sh ../../example.sh 
	../../example.sh < hello.sh > hello.exout
	../../pipkw.sh < hello.exout > hello.out

hello-var.out: hello-var.c hello-var.sh ../../example.sh
	if [ `cat /proc/sys/kernel/randomize_va_space` != 0 ]; then \
		echo "ERROR: ASLR if on"; exit 1; fi
	../../example.sh < hello-var.sh > hello-var.exout
	../../pipkw.sh < hello-var.exout > hello-var.out

hello-var-omp.out: hello-var-omp.c hello-var-omp.sh ../../example.sh
	if [ `cat /proc/sys/kernel/randomize_va_space` != 0 ]; then \
		echo "ERROR: ASLR if on"; exit 1; fi
	OMP_NUM_THREADS=2 \
	../../example.sh < hello-var-omp.sh > hello-var-omp.exout
	../../pipkw.sh < hello-var-omp.exout > hello-var-omp.out

export-import.out: export-import.c export-import.sh ../../example.sh
	pipcc export-import.c -o export-import
	../../example.sh < export-import.sh > export-import.out

clean-hook:
	$(RM) a.out export-import *.exout

veryclean-hook: 
	$(RM) *.out
