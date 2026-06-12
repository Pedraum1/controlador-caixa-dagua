#include <Arduino.h>
#include <Ultrasonic.h>
#include <LiquidCrystal_I2C.h>

#define LOGS_EN 0

#include <gpio.hpp>
#include <lcd.hpp>
#include <logs.hpp>
#include <pump.hpp>
#include <timer.hpp>
#include <utils.hpp>

LiquidCrystal_I2C display = LiquidCrystal_I2C(0x27, 20, 4);
Ultrasonic sensor = Ultrasonic(TRIGGER_PIN, ECHO_PIN);

bool manual = false;
bool pump = false;

uint16_t distance = 71;
uint16_t volume;

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
      log_info("Bomba ligada");
      while(btn_pump_pressed());

      log_info("Bomba desligada");
      pump_off();
      
      digitalWrite(MANUAL_LED_PIN, HIGH);
      digitalWrite(AUTOMATIC_LED_PIN, LOW);
    }

  } else {
    // CONTROLE AUTOMÁTICO

    digitalWrite(MANUAL_LED_PIN, LOW);
    digitalWrite(AUTOMATIC_LED_PIN, HIGH);

    // INSERIR LEITURA DO SENSOR ULTRASSONICO FILTRO

  }

  if(update_screen())
  {
    volume = calc_volume(sensor.read());

    lcd_print_volume(&display, volume);
    log_info("volume atual: " + String(volume) + "L");

    if(volume <= 50)
    {
      lcd_print_pump(&display, true);
      pump_on();
      log_info("Bomba ligada"); 
    }
    
    if(volume >= 950)
    {
      lcd_print_pump(&display, false);
      log_info("Bomba desligada");
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