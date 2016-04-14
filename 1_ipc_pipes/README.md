# Pipe - IPC
> Implement file transfer between a client and server using pipes as IPC


### Compile
```bash
$ gcc pipes.c -o pipes
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
$ ./pipes
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
