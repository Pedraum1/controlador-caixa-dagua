#include "lcd.hpp"

void lcd_config(LiquidCrystal_I2C *lcd)
{
    lcd->init();
    lcd->clear();

    lcd->setCursor(0, 0);
    lcd->print(" CONTROLADOR  CAIXA ");
    lcd->setCursor(7, 1);
    lcd->print("D'AGUA");

    delay(500);
    lcd->clear();
}