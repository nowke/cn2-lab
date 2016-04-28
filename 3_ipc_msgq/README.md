# Message queue - IPC
> Implement file transfer between a client and server using message queue

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
$ ./client.o
[CLIENT] Ouput msgq opened
[CLIENT] Input msgq opened
Enter filename: hello.txt
[CLIENT] Waiting for reply
[CLIENT] File contents
This is a
sample file to be
read
```

#### TAB 2
```bash
$ ./server.o
[SERVER] Input message queue opened
[SERVER] Waiting for client
[SERVER] Output message queue opened
[SERVER] File contents sent to client
```

### System calls used
```c
#include <sys/msg.h>
int msgget(key_t key, int flag);
// Returns: message queue ID if OK, −1 on error
```

```c
#include <sys/msg.h>
int msgsnd(int msqid, const void *ptr, size_t nbytes, int flag);
// Returns: 0 if OK, −1 on error
```

```c
#include <sys/msg.h>
ssize_t msgrcv(int msqid, void *ptr, size_t nbytes, long type, int flag);
// Returns: size of data portion of message if OK, −1 on error
```

```c
struct mymesg {
    long mtype; /* positive message type */
    char mtext[512]; /* message data, of length nbytes */
};
```
