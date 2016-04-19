/*
 * Pipes as IPC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 1000

char buffer[MAX];

void client(int readfd, int writefd) {
/*
 * 1. Reads `filename` of a file
 * 2. Writes `filename` to `writefd`
 * 3. Gets back content of file in `readfd` from server
 * 4. Prints the content to `stdout`
 */
    printf("[CLIENT] Client online\n");
    printf("[CLIENT] Pathname of file: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin); // `buffer` contains `filename`

    printf("[CLIENT] Server Online\n");
    printf("[CLIENT] Processing request\n");

    write(writefd, buffer ,sizeof(buffer));

    // Read from server
    while (read(readfd, buffer, sizeof(buffer)) > 0)
        printf("%s", buffer);
}

void server(int readfd, int writefd) {
/*
 * 1. Reads `filename` of a file from client
 * 2. Read the file contents
 * 3. Write file contents to `writefd`
 */
    FILE* f;
    char line[MAX];

    read(readfd, buffer, sizeof(buffer));
    if (strchr(buffer, '\n'))
        *strchr(buffer, '\n') = 0;

    f = fopen(buffer, "r");

    if (f == NULL) {
        // Send error msg to `writefd`
        strcpy(buffer, "[SERVER] Cannot open file\n");
        write(writefd, buffer, strlen(buffer));
        exit(1);
    } else {
        // Send file contents to `writefd`
        while (fgets(line, sizeof(line), f) != NULL)
            write(writefd, line, sizeof(line));

        sleep(1);
        printf("[SERVER] Transfer completed\n");
    }
}

int main() {
    int pipe1[2], pipe2[2];
    int childpid, status;

    pipe(pipe1);
    pipe(pipe2);

    childpid = fork();

    if (childpid > 0) {
        // Client process
        close(pipe1[0]);
        close(pipe2[1]);

        client(pipe2[0], pipe1[1]);
        wait(&status);

        exit(0);
    } else {
        // Server process
        close(pipe1[1]);
        close(pipe2[0]);

        server(pipe1[0], pipe2[1]);
        exit(0);
    }

    return 0;
}
