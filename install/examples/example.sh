#!/bin/sh
cwd=`realpath .`
LOG=/dev/null
echo "#!/bin/sh";
while read line; do
    l1=${line:1};
    case $line in
	'>'*) LOG=`realpath $l1`;;
	'@'*) echo "cd $l1";;
	'#'*) echo $line;;
	'*'*) echo "echo '$' $l1"; echo "$l1 > /dev/null";;
	'%'*) echo "echo '$' $l1"; echo "echo '...'"; echo "$l1 >> $LOG 2>&1";;
	*)    echo "echo '$' $line"; echo "$line";;
    esac
done
