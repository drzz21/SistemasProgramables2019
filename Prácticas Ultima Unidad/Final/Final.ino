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
int btnS4 = 0;


int currentmenu = 1;
bool entrasteauno = false;

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis = 0;
const unsigned long period = 2000;  //the value is a number of milliseconds

int selecta = 0;

//bs1=2 bs2=3
//bs3=4

void setup() {
  Serial.begin(9600);
  balanza.begin(DOUT, CLK);
  Wire.begin();
  lcd.backlight();
  lcd.init();
  lcd.println("<<<S.C.P.>>>");
  delay(3000);
  lcd.clear();
  lcd.setCursor( 0, 0 );
  lcd.print( "ALTURA" );
  lcd.setCursor( 0, 1 );
  lcd.print( "PESO" );


  pinMode(8, INPUT);
  digitalWrite(8, HIGH);

  pinMode(9, INPUT);
  digitalWrite(9, HIGH);

  pinMode(6, INPUT);
  digitalWrite(6, HIGH);

  pinMode(7, INPUT);
  digitalWrite(7, HIGH);

  startMillis = millis();  //initial start time




  lcd.clear();

  balanza.set_scale(235970.3014); // Establecemos la escala

  balanza.set_scale(26526.59574); // Establecemos la escala

  balanza.tare(20);  //El peso actual es considerado Tara.



}

void loop() {
  if ( digitalRead( 8 ) == LOW && btnS1 == HIGH && digitalRead( 9 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH ) {
    if (currentmenu == 1) {
      selecta = 1;
      //Serial.println("selecta = 1");
    } else if (currentmenu == 2) {
      selecta = 5;
      //Serial.println("selecta = 5");
    }
    lcd.clear();

  }
  btnS1 = digitalRead( 8 );

  //SENSOR 2
  if ( digitalRead( 9 ) == LOW && btnS2 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH && currentmenu == 1) {
    selecta = 2;

  }
  btnS2 = digitalRead( 9 );

  //SENSOR 3
  if ( digitalRead( 6 ) == LOW && btnS3 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 7 )  == HIGH && currentmenu == 1) {
    selecta = 3;

  }
  btnS3 = digitalRead( 6 );

  //SENSOR 4
  if ( digitalRead( 7 ) == LOW && btnS4 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 6 )  == HIGH && currentmenu == 1) {

    selecta = 4;



  }
  btnS4 = digitalRead( 7 );


}

void mainmenu() {
  Serial.println("dsa");

}
