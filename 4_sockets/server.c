/*
 * Sockets - Server
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <errno.h>

#define SERV_ADDR "127.0.0.1"
#define SERV_PORT 5600

int main() {
    int sockfd, client_fd, client_len, fd, n;
    int reusePort = 1;

    struct sockaddr_in server_addr, client_addr;

    char filename[256], buff[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &reusePort, sizeof(reusePort));

    // Create server address
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT); // 3000
    printf("[SERVER] Created socket\n");

    // Bind socket
    bind(sockfd,
         (struct sockaddr *) &server_addr,
         sizeof(server_addr));

    printf("[SERVER] Bind socket\n");

    // Listen for connection
    printf("[SERVER] Waiting for client\n");
    listen(sockfd, 8);

    // Accept client request
    client_len = sizeof(struct sockaddr_in);
    client_fd = accept(sockfd,
                       (struct sockaddr *) &client_addr,
                       &client_len);

    if (client_fd < 0) {
        printf("error\n");
    }

    printf("[SERVER] New connection accepted\n");

    // Read from client
    n = read(client_fd, filename, 256);
    filename[n] = '\0';

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        // File not found
        printf("[SERVER] File not found\n");
        strcpy(buff, "File not found\n");
        write(client_fd, buff, strlen(buff));
    } else {
        n = read(fd, buff, 1024);
        buff[n] = '\0';

        // write file contents to client
        write(client_fd, buff, n);

        printf("[SERVER] Transfer successfull\n");
    }

    close(client_fd);
    exit(0);
}
