/*
 * Cyclic Redundancy Check - 16 Bit (CCITT)
 */
#include <stdio.h>
#include <string.h>

int result[30];
int array[30];

int getnext(int arr[], int pos) {
    int i=pos;
    while (arr[i] == 0 && i<30) ++i;
    return i;
}

int mod2add(int x, int y) { return (x==y?0:1); }

void CRC(length) {
    int CCITT[] = {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
    int i=0, pos=0, newpos;
    while (pos < length-16) {

        for (i=pos; i<pos+16+1; ++i)
            result[i] = mod2add(result[i], CCITT[i-pos]);
        newpos = getnext(result, pos);
        if (newpos > pos+1)
            pos = newpos-1;
        ++pos;
    }
}

int main() {
    int length, i;
    char data[10];

    printf("Enter the data stream:\n");
    scanf("%s", data);
    length = strlen(data);

    // Copy data into array
    for (i=0; i<length; i++)
        array[i] = data[i]-'0';

    // Append 16 zeros to array
    for (i=0; i<16; i++)
        array[length+i] = 0;

    length += 16;
    // Copy into result array
    for (i=0; i<length; i++)
        result[i] = array[i];

    CRC(length);

    printf("Transmitted frame is: ");
    for (i=0; i<length-16; ++i)
        printf("%d", array[i]);
    for (i=length-16; i<length; i++)
        printf("%d", result[i]);

    // Decode
    printf("\nEnter the stream to decode:\n");
    scanf("%s", data);

    length = strlen(data);

    // Copy data into array
    for (i=0; i<length; i++)
        array[i] = data[i]-'0';

    // Copy into result array
    for (i=0; i<length; i++)
        result[i] = array[i];
    CRC(length);

    printf("Calculated checksum:");
    for (i=length-16; i<length; i++)
        printf("%d", result[i]);

    printf("\n");
    return 0;
}
