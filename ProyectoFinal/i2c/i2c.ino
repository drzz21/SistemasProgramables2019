#include <LiquidCrystal_I2C.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin();
  lcd.backlight();
  lcd.init();
}
void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("Holaf");
  lcd.setCursor(0, 1);
  lcd.println("Munfdo");
  delay(2000); //Se espera 2 segundos para seguir leyendo //datos
}
