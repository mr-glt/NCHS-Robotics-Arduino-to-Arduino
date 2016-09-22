#include <Wire.h>

void setup() {
  Wire.begin();
}

byte x = 0; //what we send

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  delay(500);
}
