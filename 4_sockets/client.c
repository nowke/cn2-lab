/*
 * Sockets - Client
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <errno.h>

#define SERV_ADDR "127.0.0.1"
#define SERV_PORT 5600

int main() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char filename[256], buff[1024];

    // Build the server address structure
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = inet_addr(SERV_ADDR); // 127.0.0.1
    server_addr.sin_port = htons(SERV_PORT); // 5600

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("[CLIENT] Socket created\n");

    // Connect to server
    connect(sockfd,
            (struct sockaddr *) &server_addr,
            sizeof(server_addr));

    printf("[CLIENT] Connected to server\n");

    // Get filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // write `filename` to server
    write(sockfd, filename, strlen(filename));

    printf("[CLIENT] Waiting for server\n");

    // Read file contents from server (blocking call)
    n = read(sockfd, buff, 1024);
    buff[n] = '\0';
    // Write whatever got from server (error or file contents)
    printf("[CLIENT] Reply from server\n");

    fputs(buff, stdout);

    // Close connection
    close(sockfd);

    exit(0);
}
