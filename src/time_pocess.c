#include "time_pocess.h"
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

static void error_process(const char *error)
{
    perror(error);
    exit(EXIT_FAILURE);
}

time_t get_ntp_time(const char *host, uint8_t port)
{
    int socketdr = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketdr < 0)
    {
        error_process("ERROR!!!Opening socket");
    }

    struct hostent *server = gethostbyname(host);
    if (server == NULL)
    {
        error_process("ERROR!!!No such host found");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(port);

    if (connect(socketdr, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error_process("ERROR!!!No connecting");
    }

    const uint8_t msg[48] = {8, 0};
    int res = write(socketdr, msg, sizeof(msg));
    if (res < 0)
    {
        error_process("ERROR!!!Writing socket");
    }

    uint32_t buf[1024] = {0};
    res = read(socketdr, buf, sizeof(buf));
    if (res < 0)
    {
        error_process("ERROR!!!Reading from socket");
    }

    close(socketdr);

    return (time_t)buf[4];
}

void set_sys_time(const time_t *ntp_time)
{
    struct timespec time_set = {*ntp_time, 0};
    if (-1 == clock_settime(CLOCK_REALTIME, &time_set))
    {
        error_process("ERROR!!!NTP and Sys time synchronization");
    }
}
