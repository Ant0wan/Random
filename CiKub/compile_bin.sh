#!/bin/bash

# Build image for compiler to work
docker build -t mygcc:0 $PWD/bin/

sources_path=$PWD/bin/sources/
bin_path=$PWD/bin/

# Compile each name.c file to name bin
for bin in $PWD/bin/sources/*.c
do
	name=$(echo "$bin" | cut -f1 -d '.')
	docker run --rm -v $bin_path:/root mygcc:0 gcc $bin -o $name
done
