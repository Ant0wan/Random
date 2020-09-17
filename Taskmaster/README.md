# Taskmaster [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

ON-BUILDING

An implementation of a **process supervisor** [42 project].

This project aims to get familiar with Flex-Bison, interprocess communication using UNIX domain sockets and job control mechanisms on UNIX-like operating systems.

---

## Description

- [X] Argp to parse command line arguments

- [ ] Flex-Bison for Json file parsing

- [ ] Client server

- [ ] Impletement interproc communication

System for controlling process state
Supervisor is a system for controlling and maintaining process state, similar to what init does, but not intended as an init replacement. It will manage individual processes or groups of processes that need to be started and stopped in order, and it is possible to control individual process state via an rpc mechanism, thus allowing ordinary users to restart processes.

Taskmaster is a client-server system controlling supervised processes on UNIX-like operating systems.

For this project, all libraries were allowed for the parsing of configuration files and managing the client/server relationship.However, for the rest of the project development only the use of the C standard library was allowed.

## Usage

```shell=
git clone --recurse-submodule https://github.com/Ant0wan/Taskmaster && cd Taskmaster && make -j
```
