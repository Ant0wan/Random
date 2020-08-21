#!/bin/bash
for redirection in `bash redir.sh`
do
	for bin in `bash cmd.sh`
	do
		for file in `bash file.sh`
		do
			echo "$file file ; $bin $redirection file ; rm -rf file"
		done
	done
done
