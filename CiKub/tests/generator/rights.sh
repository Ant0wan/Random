#!/bin/bash
# Usage: bash chmod_generator.sh "filename"
# Generate chmod from 0000 to 7777
for a in {0..7}
do
	for b in {0..7}
	do
		for c in {0..7}
		do
			for d in {0..7}
			do
				echo "chmmod $a$b$c$d $1"
			done
		done
	done
done
