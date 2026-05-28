#include "gpio.hpp"

void gpio_config()
{
    pinMode(PUMP_LED_PIN, OUTPUT);
    pinMode(MANUAL_LED_PIN, OUTPUT);
    pinMode(AUTOMATIC_LED_PIN, OUTPUT);
    pinMode(RELAY_PIN, OUTPUT);

    pinMode(PUMP_BUTTON, INPUT_PULLUP);
    pinMode(MANUAL_BUTTON, INPUT_PULLUP);
}

bool btn_pump_clicked()
{
    if(!digitalRead(PUMP_BUTTON))
    {
        while(!digitalRead(PUMP_BUTTON));
        return true;
    }

    return false;
}

bool btn_pump_pressed()
{
    return !digitalRead(PUMP_BUTTON);
}

bool btn_manual_clicked()
{
    if(!digitalRead(MANUAL_BUTTON))
    {
        while(!digitalRead(MANUAL_BUTTON));
        return true;
    }

    return false;
}
