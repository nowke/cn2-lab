/*
 * FIFO as IPC - Client
 */
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666

/*
 * 1. `fifo1` -> Write end ->  `writefd`
 * 2. `fifo2` -> Read end -> `readfd` (Reverse of server)
 * 3. Open connection to FIFOs created by server
 * 4. Ask user for `filename`
 * 5. Send `filename` to Server through `writefd`
 * 6. Write file contents
 */

char fname[256];
char buffer[1024];

int main() {
    int readfd, writefd, file;
    ssize_t n;

    printf("[CLIENT] Connecting to Server\n");

    writefd = open(FIFO1, O_WRONLY);
    readfd  = open(FIFO2, O_RDONLY);
    printf("[CLIENT] Connected to server\n");

    // Get filename from user
    printf("[CLIENT] Enter filename: ");
    scanf("%s", fname);

    // Send `fname` to server
    write(writefd, fname, strlen(fname));
    printf("[CLIENT] Requesting server for file content\n");

    // Read content (blocking call)
    while ((n = read(readfd, buffer, 1024)) > 0)
        printf("%s", buffer);

    close(readfd);
    close(writefd);

    return 0;
}
