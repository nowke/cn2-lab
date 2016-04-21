# Internet Checksum
> Write a program to demonstrate the Internet checksum algorithm for operation on
8bit, 12 bit and 16bit.

### Compile
```bash
$ gcc checksum.c -lm -o checksum.o
```

### Run
```bash
$ ./checksum.o
1. 8-bit, 2. 12-bit, 3. 16-bit
Choice?: 1

SENDER
===========
No. of inputs: 4

Enter 8 bit numbers (0 to 255)Enter 0 after 4 inputs
56 43 51 88 0

Checksum: 17
Transmitted data (input+checksum)
56	43	51	88	17

RECEIVER
=========
Enter received values
56 43 51 88 17

Checksum = 0
No error
```

```bash
$ ./checksum.o
1. 8-bit, 2. 12-bit, 3. 16-bit
Choice?: 2

SENDER
===========
No. of inputs: 3

Enter 12 bit numbers (0 to 4095)Enter 0 after 3 inputs
567 477 2500 0

Checksum: 551
Transmitted data (input+checksum)
567	477	2500	551

RECEIVER
=========
Enter received values
567 477 2500 550

Checksum = 4094
Error
```
