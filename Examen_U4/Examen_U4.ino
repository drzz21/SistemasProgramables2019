#include <LiquidCrystal.h>
#include "SR04.h"
#define TRIG_PIN 13
#define ECHO_PIN 10
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int btnS1 = 0;
int btnS2 = 0;
int btnS3 = 0;
int btnS4 = 0;

int estadoboton1 = 0;
int estadoboton2 = 0;
int estadoboton3 = 0;
int estadoboton4 = 0;

int trig = 13;
int echo = 10;
int duracion;
int distancia;

int LDRpin = A0;
int LDRvalor = 0;
int LDRled = 13;
float LDRvoltaje = 0.0;


//b1=8 b2=9
//b3=6 b4=7

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  Serial.begin(9600);

  pinMode(8, INPUT);
  digitalWrite(8, HIGH);

  pinMode(9, INPUT);
  digitalWrite(9, HIGH);

  pinMode(6, INPUT);
  digitalWrite(6, HIGH);

  pinMode(7, INPUT);
  digitalWrite(7, HIGH);

  pinMode(LDRpin, INPUT);
  pinMode(LDRled, OUTPUT);

}

void loop() {
  if ( digitalRead( 8 ) == LOW && btnS1 == HIGH && digitalRead( 9 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH) {

    lcd.setCursor( 2, 0 );
    lcd.print( "SENSOR 1" );
    do {
      lcd.clear();
      lcd.setCursor( 2, 0 );
      lcd.print( "SENSOR 1" );
      a = sr04.Distance();
      Serial.print(a);
      Serial.println("cm");
      lcd.setCursor( 2, 1 );
      lcd.print( a );
      lcd.print("cm");
      delay(1000);
    } while (digitalRead( 9 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH);

  }
  btnS1 = digitalRead( 8 );

  if ( digitalRead( 9 ) == LOW && btnS2 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH) {

    lcd.setCursor( 2, 0 );
    lcd.print( "SENSOR 2" );
    do {
      lcd.clear();
      lcd.setCursor( 2, 0 );
      lcd.print( "SENSOR 1" );

      LDRvalor = analogRead(LDRpin);
      LDRvoltaje = LDRvalor * (5.0 / 1023.0);
      lcd.setCursor( 2, 1 );
      lcd.print("V: ");
      lcd.print(LDRvoltaje);
      delay(500);
    } while (btnS2 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH);
  }
  btnS2 = digitalRead( 9 );

  if ( digitalRead( 6 ) == LOW && btnS3 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 7 )  == HIGH) {

    lcd.setCursor( 2, 0 );
    lcd.print( "SENSOR 3" );
  }
  btnS3 = digitalRead( 6 );

  if ( digitalRead( 7 ) == LOW && btnS4 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 6 )  == HIGH) {

    lcd.setCursor( 2, 0 );
    lcd.print( "SENSOR 4" );
  }
  btnS4 = digitalRead( 7 );

}
