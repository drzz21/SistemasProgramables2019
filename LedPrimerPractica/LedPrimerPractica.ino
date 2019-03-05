int conta = 0;
const int  buttonPin = 2;
int buttonPushCounter = 0;
int buttonState = 0;

const int ledPin = 13;
int lastButtonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {

    if (buttonState == HIGH) {

      buttonPushCounter++;
    }
    else {
    }
  }

  lastButtonState = buttonState;


  if (buttonPushCounter==5) {
    digitalWrite(ledPin, HIGH);
    delay(10000);
    digitalWrite(ledPin, LOW);
    buttonPushCounter=0;
  }
}
