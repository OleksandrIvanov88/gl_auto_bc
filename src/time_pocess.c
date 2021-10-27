#include "time_pocess.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

void error_handling(const char *error)
{
    perror(error);
    exit(EXIT_FAILURE);
}

time_t get_ntp_time(const char *host, uint16_t port)
{
    if (NULL == host)
    {
        errno = EFAULT;
        error_handling("ERROR!!!NULL pointer passed to the function get_ntp_time");
    }
    int socketdr = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketdr < 0)
    {
        error_handling("ERROR!!!Opening socket");
    }

    struct hostent *server = gethostbyname(host);
    if (server == NULL)
    {
        error_handling("ERROR!!!No such host found");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(port);

    if (connect(socketdr, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error_handling("ERROR!!!No connecting");
    }

    const uint8_t msg[48] = {8, 0};
    int res = write(socketdr, msg, sizeof(msg));
    if (res < 0)
    {
        error_handling("ERROR!!!Writing socket");
    }

    uint32_t buf[1024] = {0};
    res = read(socketdr, buf, sizeof(buf));
    if (res < 0)
    {
        error_handling("ERROR!!!Reading from socket");
    }

    close(socketdr);

    return (time_t)buf[4];
}

void set_sys_time(const time_t *set_time)
{
    if (NULL == set_time)
    {
        errno = EFAULT;
        error_handling("ERROR!!!NULL pointer passed to the function set_sys_time");
    }
    struct timespec time_set = {*set_time, 0};
    if (-1 == clock_settime(CLOCK_REALTIME, &time_set))
    {
        error_handling("ERROR!!!NTP and Sys time synchronization");
    }
}
