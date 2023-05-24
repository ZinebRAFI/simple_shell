SIMPLE_SHELL Project
____________________

This repository contains the code for a simple_shell programm develeped by 'Saad ELHAIMER' and 'Zineb RAFI'.

Description:
___________

The simple shell project is a command line compiler written in the c programming language.The program should have exactly the same output as sh "/bin/sh" and exactly the same error output.


List of functions and system calls available:
____________________________________________

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (man 2 stat)
- lstat (man 2 lstat)
- fstat  (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

Compilation:
___________

The shell is compiled in this manner:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Testing:
_______

The shell should behave like this in interactive mode:

"$ ./hsh ($) /bin/ls hsh main.c shell.c ($) ($) exit $"

but the same is true  in non-interactive mode:

"$ echo "/bin/ls" | ./hsh hsh main.c shell.c test_ls_2 $ $ cat test_ls_2 /bin/ls /bin/ls $ $ cat test_ls_2 | ./hsh hsh main.c shell.c test_ls_2 hsh main.c shell.c test_ls_2" 