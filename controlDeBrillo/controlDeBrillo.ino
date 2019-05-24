 
const int led=3;
  int brillo;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:z                                                                                                                                             
  for(brillo=0; brillo < 256; brillo++){
    analogWrite(led, brillo);
    delay(10);
  }
    //brillo=255;
    
}
