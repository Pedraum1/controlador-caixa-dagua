#ifndef LOGS_HPP
#define LOGS_HPP

    #ifndef BAUD_RATE
        #define BAUD_RATE 9600
    #endif

    #ifndef LOGS_EN
        #define LOGS_EN 1
    #endif

#include <Arduino.h>

extern uint16_t logs_counter;

void log_config();
void log_info(String message);
void log_warning(String message);
void log_error(String message);

#endif