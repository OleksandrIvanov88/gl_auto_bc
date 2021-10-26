#pragma once

#include <time.h>
#include <stdint.h>

time_t get_ntp_time(const char *host, uint8_t port);
void set_sys_time(const time_t *ntp_time);
