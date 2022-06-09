pipcc --silent -fopenmp hello-var-omp.c
export OMP_NUM_THREADS=2
./a.out
pip-exec -n 2 ./a.out
mpiexec -n 2 ./a.out
