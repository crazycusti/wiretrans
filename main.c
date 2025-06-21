#include "network.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void) {
    port_t port = 12121; // Example port
    socket_t server_socket = start_server(port);
    
    if (server_socket == SOCKET_INVALID) {
        return 1;
    }

    printf("Waiting for client connections...\n");
    
    socket_t client_socket = accept_client(server_socket);
    
    if (client_socket == SOCKET_INVALID) {
        CLOSE_SOCKET(server_socket);
        return 1; // Error accepting client
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Error receiving data");
        CLOSE_SOCKET(client_socket);
        CLOSE_SOCKET(server_socket);
        return 1;
    }

    buffer[bytes_read] = '\0'; // Null-terminate the received data
    printf("Received: %s\n", buffer);

    CLOSE_SOCKET(client_socket);
    CLOSE_SOCKET(server_socket);
    
    return 0;
}