#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int starttime = 0;
int activetime;
int prevoustime = 0;

int hours = 0;
int mins = 0;

int ahours = 12;
int amins = 0;
int ahours2 = 12;
int amins2 = 0;

long unsigned nextSeconds = 1000;
int led = 0;

int btnMinLast = 0;
int btnHourLast = 0;

int btnMinHLast = 0;
int btnHourHLast = 0;

int btnMilitar = 0;

int btnPosponer = 0;

int numberAlarm = 1;

bool militar = false;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();

  Serial.begin(9600);



  pinMode(13, INPUT);
  digitalWrite(13, HIGH);



  pinMode(15, OUTPUT);
  digitalWrite(15, HIGH);



  pinMode(11, INPUT);
  digitalWrite(11, HIGH);
  pinMode(10, INPUT);
  digitalWrite(10, HIGH);

  pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  pinMode(12, INPUT);
  digitalWrite(12, HIGH);

  pinMode(9, OUTPUT);

  starttime = millis() / 1000;
}

void loop()
{

  if ( nextSeconds <= millis()  ) {
    if ( led == LOW ) {
      led = HIGH;
    } else {
      led = LOW;
    }
    nextSeconds += 1000;
  }
  digitalWrite(15, led);

  if( digitalRead( 10 ) == LOW && btnMilitar == HIGH && digitalRead( 13 ) == HIGH && digitalRead( 8 )  == HIGH ){
    ahours = 12;
    ahours2 = 12;
    lcd.clear();
    lcd.setCursor( 0, 0 );
    if( militar ){
      lcd.print( "12" );
      militar = false;
    }else{
      lcd.print( "24" );
      militar = true;
    }
    lcd.setCursor( 2, 0 );
    lcd.print( "horas" );
  }
  btnMilitar = digitalRead( 10 );

  if (digitalRead(8) == LOW)
  {
    lcd.setCursor(6, 1);
    lcd.print("Alarma");
    lcd.setCursor(6, 0);


    if (digitalRead(11) == LOW && btnMinLast == HIGH )
    {
      if ( numberAlarm == 1 ) {
        amins++;
      } else {
        amins2++;
      }
    }
    btnMinLast = digitalRead(11);

    if (digitalRead(10) == LOW && btnHourLast == HIGH)
    {
      if ( numberAlarm == 1 ) {
        ahours++;
      } else {
        ahours2++;
      }
    }
    btnHourLast = digitalRead(10);

    lcd.setCursor(6, 0);

    if ( numberAlarm == 1 ) {
      printAlarm1();
    } else {
      printAlarm2();
    }

  }

  if (digitalRead(13) == LOW)
  {
    lcd.setCursor(5, 1);
    lcd.print("Editar hora");
    lcd.setCursor(6, 0);
    if (digitalRead(11) == LOW && btnMinHLast == HIGH)
    {
      mins++;
      if ( mins == 60 ) {
        mins = 0;
        hours++;
        if ( militar ) {
          if ( hours == 24 ) {
            hours = 0;
          }
        } else {
          if ( hours == 13 ) {
            hours = 1;
          }
        }
      }
    }

    btnMinHLast = digitalRead(11);
    if (digitalRead(10) == LOW && btnHourHLast == HIGH)
    {
      hours++;
      if (militar) {
        if ( hours == 24 ) {
          hours = 0;
        }
      } else {
        if ( hours == 13 ) {
          hours = 1;
        }
      }
    }
    btnHourHLast = digitalRead(10);

    lcd.setCursor(6, 0);

    if (hours < 10)
    {
      lcd.print("0");
    }
    lcd.print(hours);


    lcd.print(":");

    if (mins < 10)
    {
      lcd.print("0");
    }
    lcd.print(mins);


  }

  if (digitalRead(12) == LOW && btnPosponer == HIGH) {
    if ( hours == ahours && mins == amins ) {
      Serial.println("posponiendo");
      lcd.setCursor(5, 1);
      lcd.print("Posponer");
      lcd.setCursor(6, 0);
      amins += 5;
      if ( amins > 59 ) {
        ahours++;
        if ( ahours > 23 ) {
          ahours = 0;
        }
        amins = amins - 60;
      }
    } else if ( hours == ahours2 && mins == amins2 ) {
      lcd.setCursor(5, 1);
      lcd.print("Posponer");
      lcd.setCursor(6, 0);
      amins2 += 5;
      if ( amins2 > 59 ) {
        ahours2++;
        if ( ahours2 > 23 ) {
          ahours2 = 0;
        }
        amins2 = amins2 - 60;
      }
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      if ( numberAlarm == 1 ) {
        numberAlarm = 2;
      } else {
        numberAlarm = 1;
      }
      lcd.print("Alarma");
      lcd.setCursor( 7, 0 );
      lcd.print( numberAlarm );
    }
  }
  btnPosponer = digitalRead(12);


  if ( digitalRead(13) == HIGH && digitalRead(8) == HIGH && digitalRead(12) == HIGH && digitalRead( 10 ) == HIGH ) {
    activetime = (millis() / 1000) - starttime;
    if (prevoustime < (activetime - 59))
    {
      mins++;
      prevoustime = activetime;
    }

    if (mins > 59)
    {
      hours++;
      mins = 0;
    }

    if ( militar ) {
      if (hours > 23)
      {
        hours = 0;
      }
    } else {
      if (hours > 12)
      {
        hours = 0;
      }
    }



    lcd.setCursor(6, 0);

    if (hours < 10)
    {
      lcd.print("0");
      lcd.print(hours);
    }
    else
    {
      lcd.print(hours);
    }

    lcd.print(":");

    if (mins < 10)
    {
      lcd.print("0");
      lcd.print(mins);
    }
    else
    {
      lcd.print(mins);
    }



    if ( (ahours == hours && amins == mins) || (ahours2 == hours && amins2 == mins) )
    {
      tone(9, 1000, 200);
      delay(100);
      noTone(9);
      delay(100);

    }
    else
    {
      delay(300);
    }



    lcd.clear();
  }


}


void printAlarm1() {
  if (ahours < 10)
  {
    lcd.print("0");
    lcd.print(ahours);
  }
  else
  {
    lcd.print(ahours);
  }

  lcd.print(":");

  if (amins < 10)
  {
    lcd.print("0");
    lcd.print(amins);
  }
  else
  {
    lcd.print(amins);
  }
  if (amins > 59)
  {
    ahours++;
    amins = 0;
  }

  if ( militar ) {
    if (ahours > 23)
    {
      ahours = 0;
    }
  } else {
    if (ahours > 12)
    {
      ahours = 1;
    }
  }
}

void printAlarm2() {
  if (ahours2 < 10)
  {
    lcd.print("0");
    lcd.print(ahours2);
  }
  else
  {
    lcd.print(ahours2);
  }

  lcd.print(":");

  if (amins2 < 10)
  {
    lcd.print("0");
    lcd.print(amins2);
  }
  else
  {
    lcd.print(amins2);
  }
  if (amins2 > 59)
  {
    ahours2++;
    amins2 = 0;
  }
  if ( militar ) {
    if (ahours2 > 23)
    {
      ahours2 = 0;
    }
  } else {
    if (ahours2 > 12)
    {
      ahours2 = 1;
    }
  }
}

