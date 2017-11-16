/**
 * Simple example of Arduino to Arduino communication using Software Serial
 * This is the sned Arduino. It will recieve a number from the Hardware Serial
 * and will pass that reading to the Receive Arduino.
 * 
 * Gretchen Rice
 * 11/16/17
 */
 
#include <SoftwareSerial.h> //need this library to run Software Serial

SoftwareSerial mySerial(11, 10); // set up the Software serial connection to talk to the other Arduino with (transmit pin, receive pin)

int sv = 0; //sent value

void setup() {
  Serial.begin(9600); //sets up serial connection between Arduino and computer
  mySerial.begin(4800); //sets up software serial connection between 2 Arduinos
}

void loop() {
  if(Serial.available() > 0) { //checks for input from Hardware Serial
    sv = Serial.read()-'0'; //reads value from Hardware serial.
                            //-'0' converts byte to int
    mySerial.write(sv); //writes the value to the other Arduino
    Serial.println(sv); //tells us the value we are sending
  }
  
} 

