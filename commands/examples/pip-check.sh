pip-check /usr/bin/ps
pip-check /usr/bin/ls
cat /usr/bin/ls
pipcc --silent pip.c -o pip
pip-check ./pip
pipcc --silent --piptask pip.c -o pip-task
pip-check ./pip-task
pipcc --silent --piproot pip.c -o pip-root
pip-check ./pip-root
