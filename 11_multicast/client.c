/*
 * Multicast datagram - Client
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct sockaddr_in localSock;
struct ip_mreq group;

int sockfd, datalen;
char databuf[1024];

int main() {
    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    printf("[CLIENT] Opening datagram socket\n");

    // Set socket option for Reuse address
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
              (char *) &reuse, sizeof(reuse));
    printf("[CLIENT] Setting SO_REUSEADDR\n");

    // Bind to local Interface
    memset((char *)&localSock, 0, sizeof(localSock));
    localSock.sin_family = AF_INET;
    localSock.sin_addr.s_addr = INADDR_ANY;
    localSock.sin_port = htons(5555);
    bind(sockfd, (struct sockaddr *)&localSock, sizeof(localSock));
    printf("[CLIENT] Binding datagram socket\n");

    // Join the multicast group
    group.imr_multiaddr.s_addr = inet_addr("225.1.1.1");
    group.imr_interface.s_addr = inet_addr("127.0.0.1");
    setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP,
              (char *)&group, sizeof(group));
    printf("[CLIENT] Adding multicast group\n");

    datalen = sizeof(databuf);
    read(sockfd, databuf, datalen);
    printf("[CLIENT] Message from multicast server:\n%s", databuf);

    close(sockfd);
}
