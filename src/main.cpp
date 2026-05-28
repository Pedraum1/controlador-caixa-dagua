#include <Arduino.h>
#include <Ultrasonic.h>
#include <LiquidCrystal_I2C.h>

#define ENABLE_LOGS 1

#include <gpio.hpp>
#include <lcd.hpp>
#include <logs.hpp>
#include <pump.hpp>

LiquidCrystal_I2C display = LiquidCrystal_I2C(0x27, 20, 4);
Ultrasonic sensor = Ultrasonic(TRIGGER_PIN, ECHO_PIN);

bool manual = false;
bool pump = false;

uint16_t distance = 0;

void setup()
{
  gpio_config();
  lcd_config(&display);
  log_config();
}

void loop()
{
  if(manual)
  {
    // CONTROLE MANUAL
    if(btn_pump_pressed())
    {
      pump_on();
      log_info("Relé ligado");

    } else {
      pump_off();
      log_info("Relé desligado");
    }


  } else {
    // CONTROLE AUTOMÁTICO
    distance = sensor.read();
    log_info("distância atual: " + String(distance) + " cm");
    
    if(distance >= 100)
    {
      pump_on();
    }

    if(distance <= 10)
    {
      pump_off();
    }

  }

  if(btn_manual_clicked())
  {
    manual = !manual;

    if(manual)
    {
      digitalWrite(MANUAL_LED_PIN, HIGH);
      digitalWrite(AUTOMATIC_LED_PIN, LOW);
      log_info("Controle manual habilitado");
  
    } else {
      digitalWrite(MANUAL_LED_PIN, LOW);
      digitalWrite(AUTOMATIC_LED_PIN, HIGH);
      log_info("Controle manual desabilitado");
    }
  }

}