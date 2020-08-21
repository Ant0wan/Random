#!/bin/bash
# Generate all know kind of files

remove="rm -rf"

# Regular files
reg0="mkdir"
reg1="touch"
reg2="mkfifo"

for i in {0..1}
do
	name=reg$i
	echo ${!name}
done


# Links
link0="ln -s sym1 sym2"
remove1="rm -rf sym1 sym2"

link1="ln -sd /dev sym1"
remove1="rm -rf sym1"

link2="ln device hard1"
remove1="rm -rf hard1"

for i in {0..2}
do
	name=link$i
	echo ${!name}
done


# Special files
nod0="mknod file b"
nod1="mknod file c"
nod2="mknod file u"
nod3="mknod file p"

for i in {0..3}
do
	for major in {1..8..2}
	do
		for minor in {1..9..3}
		do
			name=nod$i
			echo ${!name} $major $minor
		done
	done
done
