/*
 * Multicast datagram - Server
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct in_addr localInterface;
struct sockaddr_in groupSock;

int sockfd;
char databuf[1024] = "Multicast test message";
int datalen = sizeof(databuf);

int main() {
    // Create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    printf("[SERVER] Datagram socket created\n");

    // Set groupSock socket structure
    memset((char *) &groupSock, 0, sizeof(groupSock));
    groupSock.sin_family = AF_INET;
    groupSock.sin_addr.s_addr = inet_addr("225.1.1.1");
    groupSock.sin_port = htons(5555);

    // Set local interface
    localInterface.s_addr = inet_addr("127.0.0.1");

    // Set socket option for Multicast
    setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_IF,
              (char *) &localInterface, sizeof(localInterface));
    printf("[SERVER] Setting local interface\n");

    // Send group message
    sendto(sockfd, databuf, datalen, 0,
           (struct sockaddr *) &groupSock, sizeof(groupSock));
    printf("[SERVER] Sending datagram message\n");


    return 0;
}
