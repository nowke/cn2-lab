/*
 * FIFO as IPC - Server
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
 * 1. `fifo1` -> Read end ->  `readfd`
 * 2. `fifo2` -> Write end -> `writefd`
 * 3. Creates two FIFOs and opens for READ & WRITE
 * 4. Read `filename` from Client through `readfd`
 * 5. Open the file and read contents
 * 6. Send the file contents through `writefd`
 */

char fname[256];
char buffer[1024];

int main() {
    int readfd, writefd, fd;
    ssize_t n;

    // Make FIFOs
    mkfifo(FIFO1, PERMS);
    mkfifo(FIFO2, PERMS);
    printf("[SERVER] Created FIFO files\n");

    // Open connection
    readfd  = open(FIFO1, O_RDONLY, 0);
    writefd = open(FIFO2, O_WRONLY, 0);
    printf("[SERVER] Connection Established\n");

    // Read from client (blocking call)
    read(readfd, fname, 255);
    printf("[SERVER] Client requests file: %s\n", fname);

    // Read the file if exists
    if ((fd = open(fname, O_RDWR)) < 0) {
        // File not exists
        strcpy(buffer, "File does not exists!\n");
        write(writefd, buffer, strlen(buffer));
    } else {
        while ((n = read(fd, buffer, 1024)) > 0)
            write(writefd, buffer, n);
    }

    close(readfd);  unlink(FIFO1);
    close(writefd); unlink(FIFO2);

    return 0;
}
