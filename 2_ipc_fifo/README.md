# FIFO - IPC
> Implement file transfer between a client and server using FIFO as IPC

### Compile
```bash
$ gcc server.c -o server.o
$ gcc client.c -o client.o
```

### Sample File
```bash
$ cat hello.txt
This is a
sample file to be
read
```

### Run Program
#### TAB 1
```bash
$ ./server.o
[SERVER] Created FIFO files
[SERVER] Connection Established
[SERVER] Client requests file: hello.txt
```
#### TAB 2
```bash
$ ./client.o
[CLIENT] Connecting to Server
[CLIENT] Connected to server
[CLIENT] Enter filename: hello.txt
[CLIENT] Requesting server for file content
This is a
sample file to be
read
```

### System calls used

```c
#include <sys/stat.h>
int mkfifo(const char *path, mode_t mode);
// return: 0 if OK, −1 on error
```

```c
#include <fcntl.h>
int open(const char *path, int oflag, ... /* mode_t mode */ );
// return: file descriptor if OK, −1 on error
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

```c
#include <unistd.h>
int close(int fd);
// Returns: 0 if OK, −1 on error
```
