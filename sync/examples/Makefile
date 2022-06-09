
all: barrier.out

barrier: barrier.c Makefile
	pipcc barrier.c -o barrier

barrier.out: barrier barrier.sh ../../example.sh
	../../example.sh < barrier.sh > barrier.out

clean:
	rm -f barrier *~

veryclean: clean
	rm -f *.out
