#include "HX711.h"

#define DOUT  A1
#define CLK  A0

float r = 0.0;

HX711 balanza;

void setup() {

  Serial.begin(9600);
  balanza.begin(DOUT, CLK);
  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(balanza.read());
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  balanza.set_scale(35844.98886); // Establecemos la escala
  balanza.tare(20);  //El peso actual es considerado Tara.

  Serial.println("Listo para pesar");
}

void loop() {

  r = balanza.get_units(20), 2;
  Serial.println(r);

  //  Serial.print("Peso: ");
  //  Serial.print(balanza.get_units(20), 2);
  //  Serial.println(" kg");
  //  delay(500);
}
