#include <Wire.h>
int LED1=3;
int LED2=5;
int LED3=9;
int LED4=10;
int x;
int y = 0;
void setup() {
  Wire.onReceive(receiveEvent);
  Wire.begin(8);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}
void loop() {
  x = random(0,5);
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x
  Wire.endTransmission();    // stop transmitting
  if(y==0){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(y==1){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(y==2){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(y==3){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }
  if(y==4){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }
  delay(500);
}
void receiveEvent(int bytes) {
  y = Wire.read();
}
