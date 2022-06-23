pipcc --silent hello-var.c -o hello-var
./hello-var
pip-exec -n 3 ./hello-var
mpiexec -n 3 ./hello-var
