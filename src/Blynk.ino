SYSTEM_THREAD(ENABLED);
#include <blynk.h>
#include "oled-wing-adafruit.h"

OledWingAdafruit oled = oledSetup(); // initialized OLED
double temp = 0; // initialize temperature
// setup() runs once, when the device is first turned on.
void setup() {
  pinMode(A4, INPUT); // set pin to an input pin
  Blynk.begin("{TOKEN}", IPAddress(000,000,000,000),0000); // input desired parts
  Blynk.run();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  display.loop();
  temp = (((analogRead(A4) * 3.3) / 4095.0)- 0.5) * 100; 
  output = "C: " + temp + "\n" + "F: " + (temp*9/5)+32;
  oled.println(output);
  oled.display();
  if (oled.pressedA()) Blynk.notify(output);
}

oled oledSetup(){
  oled.setup(); // set up oled
  oled.clearDisplay(); // clear oled
  oled.setCursor(0,0); // move cursor to 0,0
  oled.setTextSize(0); // set text to 0
	oled.display(); // push to oled
}

}