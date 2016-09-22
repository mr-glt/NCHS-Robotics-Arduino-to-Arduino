//Dependencies(What we need to make communication work)
#include <Wire.h> //This is for i2c

//Variables
int LED1=3; //LED1 on pin 3
int LED2=5; //LED2 on pin 5
int LED3=9; //LED3 on pin 9
int LED4=10; //LED4 on pin 10

int localRandomNumber = 0; //Set to a random number in loop(). Set to 0 for saftey
int receivedRandomNumber = 0;//Set to a number in receiveEvent(). Set to 0 for saftey

void setup() {
  Serial.begin(9600); //Start serial for debug
  Wire.begin(9); //Start the i2c lib on address 8
  Wire.onReceive(receiveEvent); //Sets the function to be called when something is received
  pinMode(LED1, OUTPUT); //LED to OUTPUT
  pinMode(LED2, OUTPUT); //LED to OUTPUT
  pinMode(LED3, OUTPUT); //LED to OUTPUT
  pinMode(LED4, OUTPUT); //LED to OUTPUT
}
void receiveEvent(int bytes) { //Function called when data is recived
  receivedRandomNumber = Wire.read(); //Set the recived number to our variable
  Serial.print(receivedRandomNumber); //Print for debug
}
void loop(){
  localRandomNumber = random(0,5); //Generate a random on localRandomNumber between 0 and 4
  Wire.beginTransmission(8); // Start a conection with a device on address 8
  Wire.write(localRandomNumber); //Write the number to it
  Wire.endTransmission();   //Stop transmitting
  if(receivedRandomNumber==0){ //If our recived number is 0 then turn LEDs off
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(receivedRandomNumber==1){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(receivedRandomNumber==2){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if(receivedRandomNumber==3){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }
  if(receivedRandomNumber==4){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }
}
