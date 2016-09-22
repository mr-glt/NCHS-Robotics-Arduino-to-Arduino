#include <Wire.h>
int LED1=3;
int LED2=5;
int LED3=9;
int LED4=10;
void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  delay(1);
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
    Wire.beginTransmission(9); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
  if (x==1){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    byte y = x;
    Wire.beginTransmission(9); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
  if (x==2){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    byte y = x;
    Wire.beginTransmission(9); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
  if (x==3){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    byte y = x;
    Wire.beginTransmission(9); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
  if (x==4){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    byte y = x;
    Wire.beginTransmission(9); // transmit to device #8
    Wire.write(y);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
}
