# Pipe - IPC
> Implement file transfer between a client and server using pipes as IPC

Pipe 1 [0, 1] - READ, WRITE <br>
Pipe 2 [0, 1] - READ, WRITE

Server - Pipe 1 READ,  Pipe2 WRITE<br>
Client - Pipe 1 WRITE, Pipe2 READ

### Compile
```bash
$ gcc pipes.c -o pipes.o
```

### Sample file
```bash
$ cat hello.txt
This is a
sample file to be
read
```

### Run program
```bash
$ ./pipes.o
[CLIENT] Client online
[CLIENT] Pathname of file: hello.txt
[CLIENT] Server Online
[CLIENT] Processing request
This is a
sample file to be
read
[SERVER] Transfer completed

$ ./pipes
[CLIENT] Client online
[CLIENT] Pathname of file: nofile
[CLIENT] Server Online
[CLIENT] Processing request
[SERVER] Cannot open file
```

### System calls used

```c
#include <unistd.h>
int pipe(int fd[2]);
// Returns: 0 if OK, −1 on error
```

```c
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t nbytes);
// Returns: number of bytes read, 0 if end of file, −1 on error
```

```c
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t nbytes);
// Returns: number of bytes written if OK, −1 on error
```
