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
const unsigned long period = 5000;  //the value is a number of milliseconds

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

  //
  //BOTON 1
  //

  if ( digitalRead( 8 ) == LOW && btnS1 == HIGH && digitalRead( 9 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH ) {
    if (currentmenu == 1) {
      selecta = 1;
    } else if (currentmenu == 2) {
      selecta = 3;
    }
    lcd.clear();

  }
  btnS1 = digitalRead( 8 );

  //
  //BOTON 2
  //

  if ( digitalRead( 9 ) == LOW && btnS2 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH && currentmenu == 1) {
    if (currentmenu == 1) {
      selecta = 2;
    } else if (currentmenu == 2) {
      selecta = 4;
    }
    lcd.clear();

  }
  btnS2 = digitalRead( 9 );

  //
  //BOTON 3
  //

  if ( digitalRead( 6 ) == LOW && btnS3 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 7 )  == HIGH && currentmenu == 1) {
    selecta = 5;

  }
  btnS3 = digitalRead( 6 );



  switch (selecta) {
    case 1:
      case1();


      break;
    case 2:
      case2();


      break;
    case 3:


      case3();


      break;
    case 4:
      case4();

      break;

    case 5:
      if (!entrasteauno) {

      } else {
        mainmenu();
      }

      case4();

      break;

    default:
      mainmenu();
  }



  //aqui acaba loop
}




void case1() {
  entrasteauno = true;
  //  lcd.setCursor( 0, 0 );
  //  lcd.print( "ALTURA" );
  do {
    Wire.begin();
    lcd.backlight();
    lcd.init();
    lcd.clear();
    lcd.setCursor( 0, 0 );
    lcd.print( "ALTURA" );



    lcd.setCursor( 0, 1 );
    lcd.println("Aquivaltura: ");

    Serial.println("entra altura");



    delay(500);
  } while (digitalRead( 6 ) == HIGH);
}

void case2() {
  entrasteauno = true;
  //  lcd.setCursor( 0, 0 );
  //  lcd.print( "ALTURA" );
  do {
    Wire.begin();
    lcd.backlight();
    lcd.init();
    lcd.clear();
    lcd.setCursor( 0, 0 );
    lcd.print( "PESO" );



    lcd.setCursor( 0, 1 );
    lcd.println("Aquivapeso: ");
    Serial.println("entra peso");



    delay(500);
  } while (digitalRead( 6 ) == HIGH);

}

void case3() {
  entrasteauno = true;
  //  lcd.setCursor( 0, 0 );
  //  lcd.print( "ALTURA" );
  do {
    Wire.begin();
    lcd.backlight();
    lcd.init();
    lcd.clear();
    lcd.setCursor( 0, 0 );
    lcd.print( "I.M.C" );



    lcd.setCursor( 0, 1 );
    lcd.println("Aquivaimc: ");

    Serial.println("entra imc");

    delay(500);
  } while (digitalRead( 6 ) == HIGH);

}

void case4() {
  entrasteauno = true;
  //  lcd.setCursor( 0, 0 );
  //  lcd.print( "GRASA" );
  do {
    Wire.begin();
    lcd.backlight();
    lcd.init();
    lcd.clear();
    lcd.setCursor( 0, 0 );
    lcd.print( "GRASA" );

    lcd.setCursor( 0, 1 );
    lcd.println("Aquivagrasa: ");

    Serial.println("entra grasa");

    delay(500);
  } while (digitalRead( 6 ) == HIGH);
}






void mainmenu() {
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - startMillis >= period)  //test whether the period has elapsed
  {
    if (currentmenu == 1) {
      menu2();
      currentmenu++;
    } else if (currentmenu == 2) {
      menu1();
      currentmenu = 1;
    }
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
  }
}

void menu1() {
  selecta = 0;

  Wire.begin();
  lcd.backlight();
  lcd.init();
  lcd.clear();


  lcd.setCursor( 0, 0 );
  lcd.print( "ALTURA" );
  lcd.setCursor( 0, 1 );
  lcd.print( "PESO" );
}

void menu2() {
  selecta = 0;
  entrasteauno = false;

  Wire.begin();
  lcd.backlight();
  lcd.init();
  lcd.clear();

  lcd.setCursor( 0, 0 );
  lcd.print( "I.M.C." );
  lcd.setCursor( 0, 1 );
  lcd.print( "%GRASA" );
}
