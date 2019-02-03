# Minitalk [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

Minitalk is a little program for transfering data using UNIX signals.

---

## Description

Your executables have to named client and server


Makefile will compil the project, and will hold the usuals rules. He must recompil the program only if necessary. He must obviously compil your both exe- cutables.


◦ signal ◦ kill
◦ getpid ◦ malloc ◦ free
◦ pause ◦ sleep ◦ usleep ◦ exit

for bonuses :  sigaction



a communication programe in the form of a client and a server
The server must be launch at first, and must show his PID after the launch.

client will take in parameter : server PID and A string to deliver
client must communicate to the server the string passed in parameter.
Once the string is fully received, the server should display it.
communication between programs must be ONLY a signal help UNIX.

server must be able to show the string quickly. By quickly, If you think is too
long, so it’s certainly too long (hint : 1 second for 100 characters, it’s COLOSSAL).
Your server must be able to receive strings from multiple clients one after the other, without needing to be restart.
You have the right to use one (and only one !) global variable by program, that you have to rigorously justify at the correction.
You can use only two signals SIGUSR1 and SIGUSR2
The volume of data transmitted must be reasonable (hint: more than 8 signals for a single character is too much!)

bonuses:
Error management of transmission and re-emission segments failures.
Management of multi clients AT SAME TIME.
Datas compresions
Confirm receipt ("ping-pong")
Optimization of CPU / memory usage.

---

## OUR PROJECT

We use Shannon communication theorie.

```shell=

Source(message) ---> encodage ---> emetteur ---> canal ---> receptor ---> decodage ---> destination
     I/O      "hello"       010101  SIGUSR1     POSIX4.0     signal()   0101001:"hello"     I/O  

```

We use a protocol made of 2 headers (2 sub-protocols "client pid" and "message length") and 1 content (1sub-protocol "message").

Wrapping schema: here

### 1 sub-protocol for client pid "get_pid_protocol"
inference of 4 bits and no acknowledgement of receipt
https://i.imgur.com/dKWDfk9.gif

[![DigitTable](https://i.imgur.com/dKWDfk9.gif)](i.imgur.com/dKWDfk9.gif)

explained

### 1 sub-protocol for message length "length_protocol"

inference of 4 bits with acknowledgment of receipt

explained

### 1 sub-protocol for message content "talk_protocol"

inference of 7 bits with acknoledgment of receipt

[![AsciiTable](https://i.imgur.com/h1kykji.png)](i.imgur.com/h1kykji.png)

explained: for speed based on system signals speed limit.

### 1 check-sum mechanism for checking integrity of delivered message

