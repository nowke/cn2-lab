# Leaky Bucket algorithm
> Implement leaky bucket congestion control algorithm.

### Compile
```bash
$ gcc leaky.c -o leaky.o
```

### Run
```bash
$ ./leaky.o

Enter bucket size: 700
Enter output rate: 60
Enter no.of packets: 5

Packet no. 1 size is 886

Bucket overflow

Packet no. 2 size is 915

Bucket overflow

Packet no. 3 size is 335

No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output at the end: 35
Bucket output successful

Packet no. 4 size is 492

No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output at the end: 12
Bucket output successful

Packet no. 5 size is 421

No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output: 60
No.of bytes output at the end: 1
Bucket output successful
```
