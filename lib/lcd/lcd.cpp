#include "lcd.hpp"

void lcd_config(LiquidCrystal_I2C *lcd)
{
    lcd->init();
    lcd->clear();
    lcd->backlight();
    delay(1000);

    lcd->setCursor(0, 0);
    lcd->print(" CONTROLADOR  CAIXA ");
    lcd->setCursor(7, 1);
    lcd->print("D'AGUA");

    delay(1000);
    lcd->clear();

    lcd->setCursor(0, 0);
    lcd->print("CAIXA D'AGUA");

    lcd->setCursor(0, 1);
    lcd->print("Volume: ");
    lcd->print("0000");
    lcd->print("L");

    lcd->setCursor(0, 2);
    lcd->print("Bomba: ");
    lcd->print("DESLIGADA");

    lcd->setCursor(0, 3);
    lcd->print("Modo: ");
    lcd->print("AUTOMATICO");

}

void lcd_print_volume(LiquidCrystal_I2C *lcd, uint16_t volume)
{
    lcd->setCursor(8, 1);
    if(volume < 1000) lcd->print(" ");
    if(volume < 100) lcd->print(" ");
    if(volume < 10) lcd->print(" ");
    lcd->print(volume);
    lcd->print(" L");
}

void lcd_print_mode(LiquidCrystal_I2C *lcd, bool state)
{
    lcd->setCursor(7, 3);
    if(state)   lcd->print("MANUAL    ");
    else        lcd->print("AUTOMATICO");
}

void lcd_print_pump(LiquidCrystal_I2C *lcd, bool state)
{
    lcd->setCursor(7, 2);
    if(state)   lcd->print("LIGADA   ");
    else        lcd->print("DESLIGADA");
}
