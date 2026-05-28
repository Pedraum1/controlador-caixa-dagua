#ifndef LCD_HPP
#define LCD_HPP

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

void lcd_config(LiquidCrystal_I2C *lcd);
void lcd_print_volume(LiquidCrystal_I2C *lcd, uint16_t volume);
void lcd_print_mode(LiquidCrystal_I2C *lcd, bool state);
void lcd_print_pump(LiquidCrystal_I2C *lcd, bool state);

#endif