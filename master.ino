#include <Wire.h>
int LED1=3;
int LED2=5;
int LED3=9;
int LED4=10;

void setup() {
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  byte x = random(0,5); //what we send
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  delay(500);
}
void receiveEvent(int howMany) {
  while (1 < Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  int x = Wire.read();
  Serial.println(x);
  if (x==0){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    byte y = x;
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    delay(500);
  }
  if (x==1){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    byte y = x;
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    delay(500);
  }
  if (x==2){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    byte y = x;
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    delay(500);
  }
  if (x==3){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    byte y = x;
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    delay(500);
  }
  if (x==4){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    byte y = x;
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    delay(500);
  }
  delay(1000);
}
