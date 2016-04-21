# Hamming code
> Write a program to illustrate the hamming code concept.

### Compile
```bash
$ gcc hamming.c -o hamming.o
```

### Run Program
```bash
$ ./hamming.o
Enter 4-bit data (seperated by space)
1 0 1 0

Encoded data:
1 0 1 1 0 1 0
Enter received data (7-bit):
1 0 1 1 0 0 0

Error bit is 6
Error free data is: 1 0 1 0
```

```bash
$ ./hamming.o
Enter 4-bit data (seperated by space)
1 0 1 0

Encoded data:
1 0 1 1 0 1 0
Enter received data (7-bit):
1 0 1 1 0 1 0

Error free data
```
