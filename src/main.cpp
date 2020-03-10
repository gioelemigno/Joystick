
#include "Arduino.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"

Joystick joystick;

void setup() { // initialize the buttons' inputs:
  joystick.begin(2, A0, A1);
  Serial.begin(9600);
}

void loop() {
  joystick.readStatus();
  joystick.printStatus();
  delay(1000);
}
