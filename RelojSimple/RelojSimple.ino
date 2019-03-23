//7 Segmentos de display
int a = 12;
int b = 8;
int c = 4;
int d = 6;
int e = 7;
int f = 11;
int g = 3;

// digitoos de Display
int dg1 = 2;
int dg2 = 9;
int dg3 = 10;
int dg4 = 13;
unsigned long starthoras1lis;  //some global variables available anywhere in the program
unsigned long currenthoras1lis;
const unsigned long period = 1000;

//Punto
int dp = 5;

//Velocidad

//segundosdades,minutosenas, centenas y horas1lares
int horas1, horas2, minutos, segundos;

byte segmentos[7] = { a, b, c, d, e, f, g };
byte orden_digitos[4] = { dg1, dg2, dg3, dg4 };
byte digitos[4][4] = { { 0, 0, 0, 1 },
  { 0, 0, 1, 0 },
  { 0, 1, 0, 0 },
  { 1, 0, 0, 0 }
};
byte siete_segmentos_digitos[10][7] = { { 1, 1, 1, 1, 1, 1, 0 }, // = 0
  { 0, 1, 1, 0, 0, 0, 0 }, // = 1
  { 1, 1, 0, 1, 1, 0, 1 }, // = 2
  { 1, 1, 1, 1, 0, 0, 1 }, // = 3
  { 0, 1, 1, 0, 0, 1, 1 }, // = 4
  { 1, 0, 1, 1, 0, 1, 1 }, // = 5
  { 1, 0, 1, 1, 1, 1, 1 }, // = 6
  { 1, 1, 1, 0, 0, 0, 0 }, // = 7
  { 1, 1, 1, 1, 1, 1, 1 }, // = 8
  { 1, 1, 1, 0, 0, 1, 1 } // = 9
};
void EscribeNumero(byte digito, byte numero) {
  int secuencia = 0;
  //Activa número
  ActivarDigito(digito);
  //digitalWrite(dp,1);//Punto
  //Escribe Numero
  for (byte i = 0; i < 7; i++) {
    digitalWrite(segmentos[secuencia], siete_segmentos_digitos[numero][i]);
    ++secuencia;
  }
}

void ActivarDigito(int x) {
  digitalWrite(dg1, HIGH);
  digitalWrite(dg2, HIGH);
  digitalWrite(dg3, HIGH);
  digitalWrite(dg4, HIGH);
  switch (x) {
    case 1:
      digitalWrite(dg1, LOW);
      break;
    case 2:
      digitalWrite(dg2, LOW);
      break;
    case 3:
      digitalWrite(dg3, LOW);
      break;
    default:
      digitalWrite(dg4, LOW);
      break;
  }
}

void setup() {

  int i;
  //Inicializar Pines
  for (i = 2; i <= 13; i++)
    pinMode(i, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  start();
}

//funcion 0 a 9999
void start() {



  for (horas1 = 0; horas1 <= 9; horas1++) {

    for (horas2 = 0; horas2 <= 9; horas2++) {

      for (minutos = 0; minutos <= 5; minutos++) {

        for (segundos = 0; segundos <= 9; segundos++) {

          if (horas1 == 2 && horas2 == 4) {
            horas1 = 0;
            horas2 = 0;
            minutos = 0;
            segundos = 0;
          }




          EscribeNumero(1, segundos);
          delay(5);
          EscribeNumero(2, minutos);
          delay(5);
          EscribeNumero(3, horas2);
          delay(5);
          EscribeNumero(4, horas1);
          delay(5);

        }

      }

    }


  }

}
