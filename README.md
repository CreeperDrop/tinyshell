# TinyShell

TinyShell is a minimal UNIX-style shell written in C as a fun side project. It mainly focuses on understanding system calls, process management, readingmanual pages, and the basic structure and inner-workings of a shell enironment.

## Features

- Custom prompt: `tinyshell># `
- Forks and executes external commands with the `execve()` syscall with support for command arguments like `/bin/ls -lh`
- Waits until the child process is done using the `waitid()` syscall
- Built-in `exit` command for shell termination


## Building

```bash
make
```

## Debugging

```bash
make
```

## Running

```bash
$ ./tinyshell
tinyshell># /bin/echo Hello, TinyShell!
Hello, TinyShell!
tinyshell># 
```

## Philosophy
This project aims to demystify shell internals by building one from scratch using only core system calls and minimal dependencies, embracing the UNIX philosophy
