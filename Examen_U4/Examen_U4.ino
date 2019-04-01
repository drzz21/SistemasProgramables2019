#include <LiquidCrystal.h>
#include "SR04.h"
#define TRIG_PIN 13
#define ECHO_PIN 10
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 18;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

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

int ThermistorPin = 16;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;


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

  pinMode(16, INPUT);

}

static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if ( millis( ) - measurement_timestamp > 3000ul )
  {
    if ( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return ( true );
    }
  }

  return ( false );
}


void loop() {

  float temperature;
  float humidity;

  if ( measure_environment( &temperature, &humidity ) == true )
  {
    Serial.print( "T = " );
    Serial.print( temperature, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }

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
      lcd.print( "SENSOR 2" );

      LDRvalor = analogRead(LDRpin);
      LDRvoltaje = LDRvalor * (5.0 / 1023.0);
      lcd.setCursor( 2, 1 );
      lcd.print("V: ");
      lcd.print(LDRvoltaje);
      delay(500);
    } while (digitalRead( 8 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH);
  }
  btnS2 = digitalRead( 9 );

  //SENSOR 3

  if ( digitalRead( 6 ) == LOW && btnS3 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 7 )  == HIGH) {

    lcd.setCursor( 2, 0 );
    lcd.print( "SENSOR 3" );
    do {
      lcd.clear();
      lcd.setCursor( 2, 0 );
      lcd.print( "SENSOR 3" );

      int digitVal = analogRead(15);

      lcd.setCursor( 2, 1 );
      lcd.print(digitVal);


      delay(500);
    } while (digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 7 )  == HIGH);
  }
  btnS3 = digitalRead( 6 );

  if ( digitalRead( 7 ) == LOW && btnS4 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 6 )  == HIGH) {

    lcd.setCursor( 2, 0 );
    lcd.print( "SENSOR 4" );
    do {
      lcd.clear();
      lcd.setCursor( 2, 0 );
      lcd.print( "SENSOR 4" );

      Vo = analogRead(16);
      R2 = R1 * (1023.0 / (float)Vo - 1.0);
      logR2 = log(R2);
      T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
      Tc = T - 273.15;

      lcd.setCursor( 2, 1 );
      lcd.print("T: ");
      lcd.print(Tc);
      lcd.println(" C");

      delay(500);
    } while (digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 6 )  == HIGH);
  }
  btnS4 = digitalRead( 7 );

}
