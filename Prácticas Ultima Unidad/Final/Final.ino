#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "HX711.h"
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;
long b;

#define DOUT  A1
#define CLK  A0
HX711 balanza;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int btnS1 = 0;
int btnS2 = 0;
int btnS3 = 0;

int selecta = 0;

//bs1=2 bs2=3
//bs3=4

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);

  pinMode(3, INPUT);
  digitalWrite(3, HIGH);

  pinMode(4, INPUT);
  digitalWrite(4, HIGH);

  balanza.begin(DOUT, CLK);
  Wire.begin();
  lcd.backlight();
  lcd.init();
  lcd.println("<<<S.C.P.>>>");
  delay(1000);
  
  lcd.clear();

  balanza.set_scale(235970.3014); // Establecemos la escala

  balanza.set_scale(26526.59574); // Establecemos la escala

  balanza.tare(20);  //El peso actual es considerado Tara.



}

void loop() {
  mainmenu();


}

void mainmenu() {
  Serial.println("dsa");
  lcd.setCursor( 0, 0 );
  lcd.print( "ALTURA      PESO" );
  lcd.setCursor( 0, 1 );
  lcd.print( "IMC       %GRASA" );
}
