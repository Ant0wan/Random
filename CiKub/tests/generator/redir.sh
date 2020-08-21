#!/bin/bash
# Redirection generator

re1=">"
re2=">>"
re3="&>"
re4=">&"
re5="<"
re6="<&"
re7="<<"
re8="<<-"

for i in {1..8}
do
	name=re$i
	for n in ${!name}
	do
		echo $n
	done
done

