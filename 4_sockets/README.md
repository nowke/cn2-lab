# Sockets
> Implement file transfer between a client and server using sockets

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
[SERVER] Created socket
[SERVER] Bind socket
[SERVER] Waiting for client
[SERVER] New connection accepted
[SERVER] Transfer successfull
```
#### TAB 2
```bash
$ ./client.o
[CLIENT] Socket created
[CLIENT] Connected to server
Enter filename: hello.txt
[CLIENT] Waiting for server
[CLIENT] Reply from server
This is a
sample file to be
read
```

### System calls used

```c
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
// Returns: file (socket) descriptor if OK, −1 on error
```

```c
#include <sys/socket.h>
int bind(int sockfd, const struct sockaddr *addr, socklen_t len);
// Returns: 0 if OK, −1 on error
```

```c
#include <sys/socket.h>
int connect(int sockfd, const struct sockaddr *addr, socklen_t len);
// Returns: 0 if OK, −1 on error
```

```c
#include <sys/socket.h>
int setsockopt(int sockfd, int level, int option, const void *val,
socklen_t len);
// Returns: 0 if OK, −1 on error
```

```c
#include <sys/socket.h>
int listen(int sockfd, int backlog);
// Returns: 0 if OK, −1 on error
```

```c
#include <sys/socket.h>
int accept(int sockfd, struct sockaddr *restrict addr,
socklen_t *restrict len);
// Returns: file (socket) descriptor if OK, −1 on error
```
