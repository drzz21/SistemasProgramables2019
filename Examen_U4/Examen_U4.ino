#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int btnS1=0;

void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);

  pinMode(8, INPUT);
  digitalWrite(8, HIGH);

}

void loop() {

  if ( digitalRead( 8 ) == LOW && btnS1 == HIGH) {
    Serial.println("hola");
    lcd.clear();
    lcd.setCursor( 0, 0 );

    lcd.print( "S1" );

  }
  btnS1 = digitalRead( 8 );
}
