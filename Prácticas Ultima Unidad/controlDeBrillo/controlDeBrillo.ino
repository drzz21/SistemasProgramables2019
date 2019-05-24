
const int led = 3;
int brillo;
char Csharp[4];

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 1)
  {
    for (int i = 0; i < 4; i++) {
      Csharp[i] = Serial.read();

    }
  }

  analogWrite(led, atoi(Csharp));
}
