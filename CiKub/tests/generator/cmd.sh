#!/bin/bash
# Generate description of builtins, binaries and there options
# Options test lonely, with -- with =, with arg1=arg2, with -h and with --help

# Builtins to test
bin0=("echo")
bin1=("builtin")
bin2=("exit")
bin3=("setenv")
bin4=("unsetenv")
bin5=("cd" "L" "P")
bin6=("fg")
bin7=("bg")
bin8=("jobs")
bin9=("true")
bin10=("false")
bin11=("type")
bin12=("hash" "l" "r" "p" "d" "t")
bin13=("fc" "e" "l" "n" "r" "s")
bin14=("export" "n" "p")
bin15=("unset")
bin16=("set")
bin17=("alias")
bin18=("unalias")
bin19=("env" "i")

for i in {0..19}
do
	name=bin$i
	for n in ${!name}
	do
		echo $n
	done
done

# Binaries to test
bin20=("cat" "e")
bin21=("ls")
bin22=("ps")
bin23=("/bin/env")
bin24=("/bin/pwd" "L" "P")
bin25=("/bin/echo")
bin26=("/bin/true")
bin27=("/bin/false")
bin28=("/bin/ls")
bin29=("/bin/cat")
bin30=("/bin/ps")
bin31=("none")

for i in {20..31}
do
	name=bin$i
	for n in ${!name}
	do
		echo $n
	done
done

# List of know arg

arg0=("$")
arg1=(".")
arg2=("..")
arg3=("")
arg4=("PWD")
arg5=("HOME")
arg6=("OLDPWD")
arg7=("CDPATH")
arg8=("SHLVL")
arg9=("~")
arg10=("-")
arg11=("/dev/urandom")
arg12=("/dev/null")
arg13=("TERM")
arg14=("USER")
arg15=("LOGNAME")
arg16=("FOO")
arg17=("/bin")
arg18=("/usr")

for i in {0..18}
do
	name=arg$i
	for n in ${!name}
	do
		echo $n
	done
done
