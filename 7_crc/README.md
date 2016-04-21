# CRC - 16bit (CCITT)
> Implement CRC error detection program. Generator is CCITT-16

### Compile
```bash
$ gcc crc.c -o crc.o
```

### Run
```bash
$ ./crc.o
Enter the data stream:
1011
Transmitted frame is: 10111011000101101011
Enter the stream to decode:
10111011000101101011
Calculated checksum:0000000000000000

$ ./crc.o
Enter the data stream:
1100
Transmitted frame is: 11001100000110001100
Enter the stream to decode:
11001100000110001101        
Calculated checksum:0000000000000001
```
