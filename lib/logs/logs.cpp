#include "logs.hpp"

uint16_t logs_counter = 0;

void log_config()
{
    Serial.begin(BAUD_RATE);
    #if LOGS_EN == 1
        Serial.println("LOGS ENABLED");
    #endif

    #if LOGS_EN == 0
        Serial.println("LOGS DISABLED");
    #endif
}

void log_info(String message)
{
    #if LOGS_EN == 1
        Serial.println("LOG_I#" + String(logs_counter) + ": " + message);
        logs_counter++;
    #endif
}

void log_warning(String message)
{
    #if LOGS_EN == 1
        Serial.println("LOG_W#" + String(logs_counter) + ": " + message);
        logs_counter++;
    #endif
}

void log_error(String message)
{
    #if LOGS_EN == 1
        Serial.println("LOG_E" + String(logs_counter) + ": " + message);
        logs_counter++;
    #endif
}
