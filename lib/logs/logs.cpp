#include "logs.hpp"

uint16_t logs_counter = 0;

void log_config()
{
    Serial.begin(BAUD_RATE);
    #ifdef ENABLE_LOGS
        Serial.println("LOGS ENABLED");
    #endif

    #ifndef ENABLE_LOGS
        Serial.println("LOGS DISABLED");
    #endif
}

void log_info(String message)
{
    #ifdef ENABLE_LOGS
        Serial.println("LOG_I#" + String(logs_counter) + ": " + message);
        logs_counter++;
    #endif
}

void log_warning(String message)
{
    #ifdef ENABLE_LOGS
        Serial.println("LOG_W#" + String(logs_counter) + ": " + message);
        logs_counter++;
    #endif
}

void log_error(String message)
{
    #ifdef ENABLE_LOGS
        Serial.println("LOG_E" + String(logs_counter) + ": " + message);
        logs_counter++;
    #endif
}
