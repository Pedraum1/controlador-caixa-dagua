#ifndef GPIO_HPP
#define GPIO_HPP

#include <Arduino.h>

#define PUMP_BUTTON     A0
#define MANUAL_BUTTON   A1

#define TRIGGER_PIN     6
#define ECHO_PIN        5

#define PUMP_LED_PIN        10
#define AUTOMATIC_LED_PIN   11
#define MANUAL_LED_PIN      12
#define RELAY_PIN           2

void gpio_config();

bool btn_pump_clicked();
bool btn_pump_pressed();

bool btn_manual_clicked();
bool btn_manual_pressed();

#endif