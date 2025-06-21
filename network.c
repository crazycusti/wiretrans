#include "network.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <arpa/inet.h>




socket_t start_server(port_t port) {
    socket_t sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
    perror("Error creating socket");
    return -1;
    }

memset(&server_addr, 0, sizeof(server_addr));

server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
server_addr.sin_port = htons(port);

if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    close(sockfd);
    return -1;
}
if (listen(sockfd, 1) < 0) {
    perror("Error listening on socket");
    close(sockfd);
    return -1;
}

printf("Server started on port: %" PORT_FMT "\n", port);

return sockfd;
}

socket_t accept_client(socket_t server_socket) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    socket_t client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);

    if (client_socket == SOCKET_INVALID) {
        perror("Error accepting client connection");
        return SOCKET_INVALID;
    }

    printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
    return client_socket;
}