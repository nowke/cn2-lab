/*
 * IPC Message Queue - Server
 */
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <fcntl.h>

#define MSGSZ 10000
#define PERMS 0666

/*
 * 1. Receieve `filename` on key1 (of Type 1)
 * 2. read the file & copy file contents into `buf.mText`
 * 3. Make `buf` of Type 2 - buf.mType = 2
 * 4. Send `buf` through key2
 */

typedef struct msgbuf {
    long mType;
    char mText[MSGSZ];
} message_buf;

int main() {
    int msqID1, msqID2;
    int f, filesize, n;

    key_t key1, key2;
    size_t buf_length;
    message_buf buf;

    /* Assign unique key for both message queues */
    key1 = 1234;
    key2 = 5678;

    // Create message queues
    msqID1 = msgget(key1, PERMS); /* Input */
    printf("[SERVER] Input message queue opened\n");
    printf("[SERVER] Waiting for client\n");

    // Receive message type 1
    // `buf.mText` contains `filename`
    msgrcv(msqID1, &buf, MSGSZ, 1, 0);

    msqID2 = msgget(key2, PERMS);
    printf("[SERVER] Output message queue opened\n");

    // Read `filename` from client
    buf.mType = 2;

    if ((f = open(buf.mText, O_RDONLY)) < 0) {
        // File not found
        printf("[SERVER] File not found\n");
        strcpy(buf.mText, "File not found");

        buf_length = strlen(buf.mText) + 1;
        msgsnd(msqID2, &buf, buf_length, IPC_NOWAIT);

        printf("[SERVER] Reply sent to client\n");
    } else {
        // Read file and send file contents to client
        // through msqID2

        n = read(f, buf.mText, MSGSZ);

        buf_length = strlen(buf.mText) + 1;
        msgsnd(msqID2, &buf, buf_length, IPC_NOWAIT);

        printf("[SERVER] File contents sent to client\n");
    }

    return 0;
}
