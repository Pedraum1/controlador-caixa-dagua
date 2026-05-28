#ifndef PUMP_HPP
#define PUMP_HPP

#include <Arduino.h>

    #ifndef RELAY_PIN
        #define RELAY_PIN   13
    #endif

void pump_on();
void pump_off();

#endif