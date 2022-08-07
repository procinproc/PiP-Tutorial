#!/bin/sh
sed  -e "s/pip-exec/\<\(\\\\pipkw pip-exec\)\>/g" -e "s/pip-mode/\<\(\\\\pipkw pip-mode\)\>/g" -
