# Random C [![freetime](https://i.imgur.com/8IcDLkc.png)](i.imgur.com/8IcDLkc.png)

---

[![HitCount](http://hits.dwyl.io/Ant0wan/Random-C.svg)](http://hits.dwyl.io/Ant0wan/Random-C)

The following files are some exercises in C. They are not compliant to the Norme and may not build nor be working.


---

## Cstd

Script that diplays information about the C standard in use by gcc and variables.

Directory: `./Cstd/`

Output sample:
```
C STANDARD AND SYSTEM INFORMATION

C standard in use by default by the compiler (C17:201710L, C11:201112L, C99:199901L, ...):
__STDC_VERSION__ 201112L

Types sizeof in 64bits system:
_______ PADDING TEST _______
Type:        Size in bytes:
void             1
char             1
short            2
int              4
float            4
double           8
size_t           8
intmax_t         8
ptrdiff_t        8
pointer          8
long long        8
long double      16
va_list          24
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

Types sizeof in 32bits system:
_______ PADDING TEST _______
Type:        Size in bytes:
void             1
char             1
short            2
int              4
float            4
double           8
size_t           4
intmax_t         8
ptrdiff_t        4
pointer          4
long long        8
long double      16
va_list          4
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```

---

## Ft_ls Cross Platform [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

#### Unachieved

A small program that lists directory contents. [42 project]

[![Build Status](https://travis-ci.com/Ant0wan/Ft_ls.svg?token=VdyQsq19sYjUnnsje5hY&branch=master)](https://travis-ci.com/Ant0wan/Ft_ls)

Directory: `./Ft_ls-crossplatform/`

A cross-platform version of `/bin/ls` giving same output as MacOs & GNU Coreutils. [UNACHIEVED]

It uses the [42Libc](https://github.com/Ant0wan/42Libc).

---

## Minitalk-archive

#### Unachieved

Minitalk is a little program for transfering data using UNIX signals.

Directory: `./Minitalk-archive/`

---

## Obfuscated C Code

Various obfuscated C code samples - just for fun !

Directory: `./ObfuscatedCCode/`

---

## Tinycat

The `cat` command recoded without options nor stdin and using streams.
Program that displays the content of a file and handle basic errors.

Directory: `./Tinycat/`

---

## Trash_n_old

All old programs...

Directory: `./Trash_n_old/`

#### Linked lists exercises

Some exercises to master linked lists (structures) in `./lists/linked_lists_exercises.c`

#### Tail - Unachieved

Attempt to recode the `tail` command and learn some of its basics. Does not work. Parsing unachieved.

#### Binary Trees

Functions from 42's day13 piscine C concerning binary trees.
