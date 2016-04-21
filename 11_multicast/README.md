# Multicast Routing
> Implement a simple multicast routing mechanism.

### Compile
```bash
$ gcc server.c -o server.o
$ gcc client.c -o client.o
```

### Run Program (Always run Client first)
#### TAB 1
```bash
$ ./client.o
[CLIENT] Opening datagram socket
[CLIENT] Setting SO_REUSEADDR
[CLIENT] Binding datagram socket
[CLIENT] Adding multicast group
[CLIENT] Message from multicast server:
Multicast test message
```

#### TAB 2
```bash
$ ./server.o
[SERVER] Datagram socket created
[SERVER] Setting local interface
[SERVER] Sending datagram message
```
