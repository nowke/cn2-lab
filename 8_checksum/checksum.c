#include <stdio.h>
#include <math.h>

void CheckSum(int bit) {
    int input[50], output[50];
    int limit, checksum;
    int i,j, in=0, sum=0, num;

    // Maximum value (eg: 8bit -> 2^8 = 256 i.e. 0-255)
    limit = pow(2, bit);

    printf("\nSENDER\n===========\n");
    printf("No. of inputs: ");
    scanf("%d", &num);

    printf("\nEnter %d bit numbers (0 to %d)", bit, limit-1);
    printf("Enter 0 after %d inputs\n", num);

    for (i=0; in<limit && i<=num; i++) {
        scanf("%d", &in);
        input[i] = in;
    }

    for (j=0; j<i-1; j++)
        sum += input[j];

    checksum = (limit -1)-(sum % (limit -1));

    printf("\nChecksum: %d\n", checksum);

    input[i-1] = checksum; // Replace '0' with Checksum

    printf("Transmitted data (input+checksum)\n");
    for (j=0; j<=i-1; j++)
        printf("%d\t", input[j]);

    printf("\n\nRECEIVER\n=========\n");
    sum = checksum = 0;
    printf("Enter received values\n");
    for (j=0; j<i; j++) {
        scanf("%d", &output[j]);
        sum += output[j];
    }

    checksum = sum % (limit-1);
    printf("\nChecksum = %d\n", checksum);
    if (checksum == 0)
        printf("No error\n");
    else
        printf("Error\n");

}

int main() {
    int bit;
    printf("1. 8-bit, 2. 12-bit, 3. 16-bit\n");
    printf("Choice?: ");
    scanf("%d", &bit);

    switch(bit) {
        case 1: CheckSum(8); break;
        case 2: CheckSum(12); break;
        case 3: CheckSum(16); break;
        default:
            return 0;
    }

    return 0;
}
