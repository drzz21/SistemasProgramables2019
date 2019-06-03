
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

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
int btnS4 = 0;
String dae;


int currentmenu = 1;
bool entrasteauno = false;

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis = 0;
const unsigned long period = 3000;  //the value is a number of milliseconds

int selecta = 0;

//b1=8 b2=9
//b3=6 b4=7

void setup() {
  Serial.begin(9600);
  balanza.begin(DOUT, CLK);
  Wire.begin();
  lcd.backlight();
  lcd.init();
  lcd.println("<<<S.C.P.>>>");
  delay(2000);



  startMillis = millis();  //initial start time


  balanza.set_scale(235970.3014); // Establecemos la escala


  balanza.tare(20);  //El peso actual es considerado Tara.



}

void loop() {
  Wire.begin();
  lcd.backlight();
  lcd.init();

  do {
    dae = "";


    a = sr04.Distance();
    int b = 192 - a;
    if (b > 150) {

      lcd.setCursor( 0, 0 );
      lcd.print("Altura:");
      lcd.print(b);
      dae += b;
      Serial.println(b);
      lcd.println("c.m.");
    } else {
      
      lcd.setCursor( 0, 0 );
      lcd.println("COLOQUESE BIEN");
    }

    if (balanza.get_units(20), 3 > 0.0) {

      lcd.setCursor( 0, 1 );
      lcd.print( "Peso:" );

      lcd.println(balanza.get_units(20), 3);
      Serial.println(balanza.get_units(20), 3);

      dae += (balanza.get_units(20), 3);
    } else {
      lcd.setCursor( 0, 1 );
      lcd.print( "Peso:" );
      lcd.println("0");
    }

    delay(500);

  } while (2 < 1);


  //aqui acaba loop
}
