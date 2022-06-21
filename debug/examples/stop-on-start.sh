pipcc --silent hello.c -o hello
echo $PIP_STOP_ON_START
pip-exec -n 4 ./hello
