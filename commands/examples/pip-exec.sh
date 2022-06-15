cat prog.c
pipcc --silent prog.c -o a.out
cp a.out b.out
cp a.out c.out
pip-exec -n 2 ./a.out : -n 3 ./b.out : -n 1 ./c.out
