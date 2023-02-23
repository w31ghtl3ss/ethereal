#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "socket.h"

int socket_data_recv(int sock, SocketData *data) {
    if (!data) {
        return -1;
    }
    if (serializer_init(&data->serializer) != 0) {
        return -1;
    }
    if (serializer_set_buffer_size(&data->serializer, 65536) != 0) {
        return -1;
    }
    socklen_t addr_len = sizeof(data->addr);
    int len = recvfrom(sock, data->serializer.buffer, data->serializer.buffer_size, 0, (struct sockaddr *)&data->addr, &addr_len);
    if (len != -1 && (size_t)len < data->serializer.buffer_size) {
        if (serializer_set_buffer_size(&data->serializer, (size_t)len) != 0) {
            return -1;
        }
    }
    return 0;
}

int socket_data_send(int sock, SocketData *data) {
    sendto(sock, data->serializer.buffer, data->serializer.buffer_size, 0, (struct sockaddr *)&data->addr, sizeof(data->addr));
    return 0;
}

int socket_close(int sock) {
    close(sock);
    return 0;
}
