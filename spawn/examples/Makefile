
all: spawn.out spawn-myself.out userfunc.out mainfunc.out wait.out waitany.out \
	exit.out maps.out

spawn.out: spawn-root.c spawn-task.c spawn.sh ../../example.sh
	pipcc spawn-root.c -o spawn-root
	pipcc spawn-task.c -o spawn-task
	../../example.sh < ./spawn.sh > spawn.out

spawn-myself.out: spawn-myself.c spawn-myself.sh ../../example.sh
	pipcc spawn-myself.c -o spawn-myself
	../../example.sh < ./spawn-myself.sh > spawn-myself.out

userfunc.out: userfunc.c userfunc.sh ../../example.sh
	pipcc userfunc.c -o userfunc
	../../example.sh < ./userfunc.sh > userfunc.out

mainfunc.out: mainfunc.c mainfunc.sh ../../example.sh
	pipcc mainfunc.c -o mainfunc
	../../example.sh < ./mainfunc.sh > mainfunc.out

wait.out: wait.c exec.sh ../../example.sh
	pipcc wait.c -o wait
	../../example.sh < wait.sh > wait.out

waitany.out: waitany.c exec.sh ../../example.sh
	pipcc waitany.c -o waitany
	../../example.sh < waitany.sh  > waitany.out

exit.out: exit.c exec.sh ../../example.sh
	pipcc exit.c -o exit
	../../example.sh < exit.sh > exit.out

maps.out: maps.c maps.sh ../../example.sh
	pipcc maps.c -o maps
	./maps.sh

clean:
	rm -f spawn-root spawn-task spawn-myself userfunc mainfunc \
	wait waitany exit maps *.exout *~

veryclean: clean
	rm -f *.out
