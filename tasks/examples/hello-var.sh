pipcc --silent hello-var-omp.c
./a.out
pip-exec -n 3 ./a.out
mpiexec -n 3 ./a.out
