#include <stdio.h>

int generator[4][7] = {
    0, 1, 1, 1, 0, 0, 0,
    1, 0, 1, 0, 1, 0, 0,
    1, 1, 0, 0, 0, 1, 0,
    1, 1, 1, 0, 0, 0, 1
}; // Matrix G

int hamming[3][7] = {
    1, 0, 0, 0, 1, 1, 1,
    0, 1, 0, 1, 0, 1, 1,
    0, 0, 1, 1, 1, 0, 1
}; // Matrix H

int data[4]; // 4-bit data to be encoded
int encoded[7] = {0}; // encoded(1x7) = data(1x4) * generator(4x7)

int received[7] = {0}; // Received data
int syndrome[3] = {0}; // syndrome(1x3) = received(1x7) * hamming(7x3)

int main() {
    int i;
    printf("Enter 4-bit data (seperated by space)\n");
    for (i=0; i<4; i++)
        scanf("%d", &data[i]);

    // Multiply data with generator matrix
    for (j=0; j<4; j++)
        for (i=0; i<7; i++)
            encoded[i] += data[j] * generator[j][i];

    
}
