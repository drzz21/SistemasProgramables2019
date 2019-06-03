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

//  _     _        __ 
// | |   | |      /_ |
// | |__ | |_ _ __ | |
// | '_ \| __| '_ \| |
// | |_) | |_| | | | |
// |_.__/ \__|_| |_|_|

  if ( digitalRead( 8 ) == LOW && btnS1 == HIGH && digitalRead( 9 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH) {
    if (currentmenu == 1) {
      selecta = 1;
    } else if (currentmenu == 2) {
      selecta = 3;
    }
    lcd.clear();

  }
  btnS1 = digitalRead( 8 );

//  _     _         ___  
// | |   | |       |__ \ 
// | |__ | |_ _ __    ) |
// | '_ \| __| '_ \  / / 
// | |_) | |_| | | |/ /_ 
// |_.__/ \__|_| |_|____|

  if ( digitalRead( 9 ) == LOW && btnS2 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 6 )  == HIGH && digitalRead( 7 )  == HIGH ) {
    if (currentmenu == 1) {
      selecta = 2;
    } else if (currentmenu == 2) {
      selecta = 4;
    }
    lcd.clear();

  }
  btnS2 = digitalRead( 9 );

//  _     _         ____  
// | |   | |       |___ \ 
// | |__ | |_ _ __   __) |
// | '_ \| __| '_ \ |__ < 
// | |_) | |_| | | |___) |
// |_.__/ \__|_| |_|____/ 

  if ( digitalRead( 6 ) == LOW && btnS3 == HIGH && digitalRead( 8 ) == HIGH && digitalRead( 9 )  == HIGH && digitalRead( 7 )  == HIGH && currentmenu == 1) {
    selecta = 5;

  }
  btnS3 = digitalRead( 6 );

//               _ _       _     
//              (_) |     | |    
//  _____      ___| |_ ___| |__  
// / __\ \ /\ / / | __/ __| '_ \ 
// \__ \\ V  V /| | || (__| | | |
// |___/ \_/\_/ |_|\__\___|_| |_|

  switch (selecta) {
    case 1:
      //altura
      case1();
      break;



    case 2:
      //peso
      case2();
      break;


    case 3:
      //imc
      case3();
      break;



    case 4:
    //grasa
      case4();
      break;



    case 5:
      if (!entrasteauno) {

      } else {
        mainmenu();
      }

      break;

    default:
      mainmenu();
  }



  //aqui acaba loop
}



//        _ _
//       | | |
//   __ _| | |_ _   _ _ __ __ _
//  / _` | | __| | | | '__/ _` |
// | (_| | | |_| |_| | | | (_| |
//  \__,_|_|\__|\__,_|_|  \__,_|


void case1() {
  entrasteauno = true;

  do {
    Wire.begin();
    lcd.backlight();
    lcd.init();
    lcd.clear();
    lcd.setCursor( 0, 0 );
    lcd.print( "ALTURA" );

    lcd.setCursor( 0, 1 );
    lcd.println("Aquivaltura: ");

    delay(500);
  } while (digitalRead( 6 ) == HIGH);
}


//
//  _ __   ___  ___  ___
// | '_ \ / _ \/ __|/ _ \ 
// | |_) |  __/\__ \ (_) |
// | .__/ \___||___/\___/
// | |
// |_|

void case2() {
  entrasteauno = true;

  do {
    Wire.begin();
    lcd.backlight();
    lcd.init();
    lcd.clear();
    lcd.setCursor( 0, 0 );
    lcd.print( "PESO" );

    lcd.setCursor( 0, 1 );
    lcd.println("Aquivapeso: ");

    delay(500);
  } while (digitalRead( 6 ) == HIGH);

}

//  _
// (_)
//  _ _ __ ___   ___
// | | '_ ` _ \ / __|
// | | | | | | | (__
// |_|_| |_| |_|\___

void case3() {
  entrasteauno = true;
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


//
//   __ _ _ __ __ _ ___  __ _
//  / _` | '__/ _` / __|/ _` |
// | (_| | | | (_| \__ \ (_| |
//  \__, |_|  \__,_|___/\__,_|
//   __/ |
//  |___/

void case4() {
  entrasteauno = true;
  do {
    Wire.begin();
    lcd.backlight();
    lcd.init();
    lcd.clear();
    lcd.setCursor( 0, 0 );
    lcd.print( "GRASA" );

    lcd.setCursor( 0, 1 );
    lcd.println("Aquivagrasa: ");

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
