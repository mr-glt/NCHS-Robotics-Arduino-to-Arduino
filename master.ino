#include <Wire.h>

void setup() {
  Wire.begin();
  Wire.onReceive(receiveEvent);
}

byte x = 0; //what we send

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  delay(500);
}
void receiveEvent(int howMany) {
  /*
  while (1 < Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  */
  int x = Wire.read();
  Serial.println("There are " + x + " lights on.");
  delay(1000);
}
