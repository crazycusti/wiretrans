#ifndef NETWORK_H
#define NETWORK_H
#include <stdint.h>

/* Serverfunktionen deklarieren
TODO: config für automatische cpu/os erkennung*/

typedef int16_t socket_t;
typedef uint16_t port_t;


socket_t start_server(port_t port);
socket_t accept_client(socket_t server_socket);

#endif // NETWORK_H

