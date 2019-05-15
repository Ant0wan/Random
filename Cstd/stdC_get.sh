#!/bin/sh
printf "C STANDARD AND SYSTEM INFORMATION\n"
printf "\n"
printf "C standard in use by default by the compiler (C17:201710L, C11:201112L, C99:199901L, ...):\n"
gcc -dM -E - < /dev/null | grep __STDC_VERSION__ | cut -d ' ' -f2,3
printf "\n"
printf "Types sizeof in 64bits system:"
gcc -m64 .size_info.c && ./a.out
printf "Types sizeof in 32bits system:"
gcc -m32 .size_info.c && ./a.out
rm -f a.out
