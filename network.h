#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>

#define PORT_FMT PRIu16

/* Winsock 1.0 und POSIX, CPU Erkennung noch nötig
DOS noch nötig, später */

#ifdef _WIN32
    #include <winsock2.h>   
    typedef SOCKET socket_t;    
    #define CLOSE_SOCKET(s) closesocket(s)
    #define SOCKET_INVALID INVALID_SOCKET
#else
    #include <stdio.h>
    #include <netinet/in.h>
    #include <string.h>
    #include <unistd.h>
    #include "network.h"
    #include <arpa/inet.h>
    #include <sys/socket.h>
    typedef int16_t socket_t;
    typedef uint16_t port_t;
    #define SOCKET_INVALID -1
    #define CLOSE_SOCKET(s) close(s)  
#endif

/* Serverfunktionen deklarieren */

socket_t start_server(port_t port);
socket_t accept_client(socket_t server_socket);

#endif // NETWORK_H

