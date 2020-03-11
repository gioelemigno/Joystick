
#include "Arduino.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"
#include "LayoutPosition.h"

Joystick joystick;
LayoutPosition layoutPosition;

void setup() { 
  joystick.begin(2, A0, A1);
  Serial.begin(9600);
      delay(5000);

  Serial.println("wainting calibartion...");
    joystickStatus_t* status = joystick.readStatus();
  point_t middle = {.x=status->x, .y=status->y};
  
  layoutPosition.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, middle);

  delay(5000);
  Serial.println("done");
    layoutPosition.printAllPosition();

}

void loop() {
  //layoutPosition.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, LayoutPosition::abs_centerADC_point);

  joystickStatus_t* status = joystick.readStatus();

  Position* pos = layoutPosition.getPosition(status->x, status->y, status->button_pressed);
  layoutPosition.printPosition(pos);
  joystick.printStatus();
  Serial.println("...........................\n\n\n");
  delay(1000);
}
