#include <Wire.h>



void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  byte y = random(0,5); //what we send
  Wire.beginTransmission(9); // transmit to device #8
  Wire.write(y);              // sends one byte
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

}
