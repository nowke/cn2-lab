#include <stdio.h>
#include <unistd.h>

void leakyBucket(int bucket_size, int output_rate, int packet_size) {
    if (packet_size > bucket_size)
        printf("\nBucket overflow\n");
    else {
        sleep(1);
        while (packet_size > output_rate) {
            printf("\nNo.of bytes output: %d", output_rate);
            packet_size -= output_rate;
            sleep(1);
        }

        printf("\nNo.of bytes output at the end: %d", packet_size);
        printf("\nBucket output successful\n");
    }
}

int main() {
    int bucket_size, output_rate,
        packets, packet_size, delay;
    int i;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter output rate: ");
    scanf("%d", &output_rate);

    printf("Enter no.of packets: ");
    scanf("%d", &packets);

    for (i=0; i<packets; i++) {
        delay = rand() % 10;
        sleep(delay);

        packet_size = rand() % 1000;

        printf("\nPacket no. %d size is %d\n", i+1, packet_size);
        leakyBucket(bucket_size, output_rate, packet_size);
    }
}
