/*
 * Hamming code
 */
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
    int i,j;
    printf("Enter 4-bit data (seperated by space)\n");
    for (i=0; i<4; i++)
        scanf("%d", &data[i]);

    // Multiply data with generator matrix
    for (j=0; j<4; j++)
        for (i=0; i<7; i++)
            encoded[i] += data[j] * generator[j][i];

    // Replace even with 0, odd with 1
    for (i=0; i<7; i++)
        encoded[i] = encoded[i] % 2;

    printf("\nEncoded data:\n");
    for (i=0; i<7; i++)
        printf("%d ", encoded[i]);

    // Receiver
    printf("\nEnter received data (7-bit):\n");
    for (i=0; i<7; i++)
        scanf("%d", &received[i]);

    // Multiply with hamming matrix(H)
    for (i=0; i<3; i++)
        for (j=0; j<7; j++)
            syndrome[i] += hamming[i][j] * received[j];

    // Replace even with 0, odd with 1
    for (i=0; i<7; i++)
        syndrome[i] = syndrome[i] % 2;

    // Error detection
    for (i=0; i<7; i++)
        if (syndrome[0] == hamming[0][i] &&
            syndrome[1] == hamming[1][i] &&
            syndrome[2] == hamming[2][i])
            break;

    // Error correction
    if (i==7)
        printf("\nError free data\n");
    else {
        printf("\nError bit is %d\n", i+1);
        received[i] = !received[i];
        printf("Error free data is: ");
        for (j=3; j<7; j++)
            printf("%d ", received[j]);
        printf("\n");
    }

    return 0;
}
