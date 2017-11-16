/**
 * Simple example of Arduino to Arduino communication using Software Serial
 * This is the reive Arduino. It will recieve a number from the Send Arduino
 * and will turn the built in LED on or off accordingly.
 * 
 * Gretchen Rice
 * 11/16/17
 */

#include <SoftwareSerial.h> //need this library to run Software Serial

SoftwareSerial mySerial(11, 10); // set up the Software serial connection to talk to the other Arduino with (transmit pin, receive pin)

bool state = LOW; //sets state of the light
int rv = 0; //received value

void setup() {
  Serial.begin(9600); //sets up serial connection between Arduino and computer
  mySerial.begin(4800); //sets up software serial connection between 2 Arduinos

  pinMode(LED_BUILTIN, OUTPUT); //sets up light as Arduino built in light
}


void loop() {
  if(mySerial.available() > 0){ //if there is a serial value 
    Serial.println("Receiving"); //alerts us we are receiving from other Arduino
    rv = mySerial.read(); //sets rv equal to the number we are recieving from the other Arduino
                          //receives ints, not bytes like Hardware Serial
    Serial.println(rv); //tells us what we recieved
  }
  // put your main code here, to run repeatedly:
  if(rv==0){ //turns state off if recieved 0
    state = LOW;
  }
  else if(rv==1){ //turns state on if recieved 1
    state = HIGH;
  }

  digitalWrite(LED_BUILTIN, state); //sets state of light depending on received value
}
