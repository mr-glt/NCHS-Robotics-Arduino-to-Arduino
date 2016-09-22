#include <Wire.h>

byte y = 0; //what we send

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  int x = Wire.read();
  Serial.println(x);
  delay(1000);
  send();
}

void send(){
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(y);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}
