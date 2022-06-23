pipcc --silent -fopenmp hello-var-omp.c -o hello-var-omp
export OMP_NUM_THREADS=2
./hello-var-omp
pip-exec -n 2 ./hello-var-omp
mpiexec -n 2 ./hello-var-omp
