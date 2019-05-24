const int led = 3;
int brillo;
byte Csharp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {

    Csharp = Serial.read();

    Serial.println(Csharp, DEC);

    analogWrite(led, int(Csharp));

  }
}
