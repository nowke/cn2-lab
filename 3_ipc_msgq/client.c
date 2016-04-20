/*
 * IPC Message Queue - Client
 */
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <fcntl.h>

#define MSGSZ 10000

/*
 * 1. Send `filename` through key1 (Type 1)
 * 2. Receieve file contents from key2 (Type 2)
 * 3. Print file contents into stdout
 */

typedef struct msgbuf {
    long mType;
    char mText[MSGSZ];
} message_buf;

int main() {
    int msqID1, msqID2;
    int msgflag = IPC_CREAT | 0666;

    key_t key1, key2;
    size_t buf_length;
    message_buf buf;

    /* Assign unique key for both message queues */
    key1 = 1234;
    key2 = 5678;

    // Create message queues
    msqID1 = msgget(key1, msgflag);
    printf("[CLIENT] Ouput msgq opened\n");
    msqID2 = msgget(key2, msgflag);
    printf("[CLIENT] Input msgq opened\n");

    buf.mType = 1;
    // Get filename
    printf("Enter filename: ");
    scanf("%s", buf.mText);

    // Send filename
    buf_length = strlen(buf.mText) + 1;
    msgsnd(msqID1, &buf, buf_length, IPC_NOWAIT);
    printf("[CLIENT] Waiting for reply\n");

    msgrcv(msqID2, &buf, MSGSZ, 2, 0);

    printf("[CLIENT] File contents\n");
    fputs(buf.mText, stdout);

    return 0;
}
