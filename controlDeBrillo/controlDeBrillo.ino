 
const int led=10;
  int brillo;
  const int potenciometro = A0;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:z                                                                                                                                             

    brillo= analogRead(potenciometro)/4;
    analogWrite(led, brillo);
}
