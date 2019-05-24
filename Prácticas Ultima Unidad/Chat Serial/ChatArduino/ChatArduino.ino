#include <SoftwareSerial.h>

SoftwareSerial chat(10, 11); // RX, TX

int text;

void setup()
{
  // abrir seriales, TX = 1, RX = 0
  Serial.begin(9600);
  Serial.println("Iniciado chat...");
  chat.begin(9600);
  delay(1000);
  chat.println("...");
}

void loop()
{
  if (chat.available())
    Serial.write(chat.read());

  if (Serial.available())
  {
    Serial.print("Yo:\t");
    while (Serial.available())
    {
      text = Serial.read();
      chat.write(text);
      Serial.write(text);
    }
    chat.println();
    Serial.println();
  }
}
