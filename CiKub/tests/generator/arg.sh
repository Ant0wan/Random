#!/bin/bash
# Generate random arguments


# Generate num arg
for i in {-255..1028..1}
do
	echo $i
done


# Generate filename for file system
for i in `ls -R ~/`
do
	echo $i | rev | cut -d '/' -f1 | rev
done


# Generate otpions
function arg_gen()
{
	local chars='{a..z}'
	local str=''
	for ((CNTR = 0; CNTR < $1; CNTR += 1))
	do
		str=$str$chars
		for i in `eval echo "$str"`
		do
			echo $i
		done
	done
}

arg_gen 3
