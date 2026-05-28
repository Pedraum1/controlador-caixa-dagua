#include "pump.hpp"

void pump_on()
{
    digitalWrite(RELAY_PIN, HIGH);
}

void pump_off()
{
    digitalWrite(RELAY_PIN, LOW);
}
