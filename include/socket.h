#ifndef SOCKET_H_
#define SOCKET_H_

#include <stdint.h>
#include <netinet/in.h>
#include "serializer.h"

typedef struct {
    Serializer serializer;
    struct sockaddr_in addr;
} SocketData;

int socket_bind(uint16_t port);

int socket_data_recv(int sock, SocketData *data);

int socket_data_send(int sock, SocketData *data);

int socket_close(int sock);

#endif // SOCKET_H_
