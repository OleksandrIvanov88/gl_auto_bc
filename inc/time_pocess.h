#pragma once

#include <time.h>
#include <stdint.h>

/**
 * @brief provide NTP time from the server  
 * @param host - host address
 * @param port - port
 * @return time as the time_t structure 
 * */
time_t get_ntp_time(const char *host, uint16_t port);

/**
 * @brief set system time ti the dedicated value, sudo rights required 
 * @param set_time - time to set as the time_t structure 
 * */
void set_sys_time(const time_t *set_time);

/**
 * @brief handels the error using global variable errno. Display error and terminate the service. 
 * @param error - Text to print with the errno. 
 * */
void error_handling(const char *error);
