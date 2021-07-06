#include "oled-wing-adafruit.h"
#include <blynk.h>
SYSTEM_THREAD(ENABLED);
OledWingAdafruit oled;
// setup() runs once, when the device is first turned on.
void setup() {
  Blynk.begin("{TOKEN}", IPAddress(000,000,000,000),0000); // in setup
  Blynk.run();
  double temp = 0; // initialize temperature
  pinMode(A4, INPUT); // set pin to an input pin
  pinMode(D5, INPUT); // reads if A is pressed
  Serial.begin(9600); // cereal begin
  oled.setup(); // set up oled
	oled.display(); // push to oled

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  temp = (((analogRead(A4) * 3.3) / 4095.0)- 0.5) * 100; 
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.print(temp);
  oled.display();
  if(digitalRead(D5) = HIGH){ // if D5 is on
    Blynk.notify(temp); // notifies once checked
  }

}