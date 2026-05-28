#include <Arduino.h>
#include <Ultrasonic.h>
#include <LiquidCrystal_I2C.h>

#define LOGS_EN 0

#include <gpio.hpp>
#include <lcd.hpp>
#include <logs.hpp>
#include <pump.hpp>
#include <timer.hpp>

LiquidCrystal_I2C display = LiquidCrystal_I2C(0x27, 20, 4);
Ultrasonic sensor = Ultrasonic(TRIGGER_PIN, ECHO_PIN);

bool manual = false;
bool pump = false;

uint16_t distance = 0;
uint16_t volume = 0;

void setup()
{
  gpio_config();
  lcd_config(&display);
  log_config();
  timer_config();
}

void loop()
{
  if(manual)
  {
    // CONTROLE MANUAL
    if(btn_pump_pressed())
    {
      pump_on();
      // log_info("Bomba ligada");

    } else {
      pump_off();
      // log_info("Bomba desligada");
    }

  } else {
    // CONTROLE AUTOMÁTICO

    // distance = sensor.read();
    if(update_screen())
    {
      if(volume < 100)
      {
        volume += 5;
      }

      lcd_print_volume(&display, volume);
      log_info("volume atual: " + String(volume) + "L");

    }
    
    if(volume <= 10)
    {
      lcd_print_pump(&display, true);
      pump_on();
      // log_info("Bomba ligada"); TODO: ENCONTRAR FORMA DE LOGGAR OS DADOS DA BOMBA
    }
    
    if(volume >= 90)
    {
      lcd_print_pump(&display, false);
      // log_info("Bomba desligada"); TODO: ENCONTRAR FORMA DE LOGGAR OS DADOS DA BOMBA
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