#!/bin/sh

output="pipkw.sh"
pipkws="pip-exec pip-mode"

texbegin="\<\("
texcmd="\\\\\\\\pipkw "
texend="\)\>"

sedcmd=
for kw in $pipkws; do
    sedcmd="${sedcmd} -e \"s/${kw}/${texbegin}${texcmd}${kw}${texend}/g\""
done

cat << EOF > ${output}
sed ${sedcmd} -
EOF

chmod +x ${output}
	       
