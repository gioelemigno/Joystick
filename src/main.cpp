
#include "Arduino.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"
#include "LayoutPosition.h"
#include "CustomLayoutPosition.h"

Joystick joystick;
LayoutPosition layoutPosition;
LayoutPosition_cross cross;

void setup() { 
  joystick.begin(2, A1, A0);
  Serial.begin(9600);
      delay(5000);

  Serial.println("wainting calibartion...");
    joystickStatus_t* status = joystick.readStatus();
  point_t middle = {.x=status->x, .y=status->y};
  
  cross.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, middle);

  //layoutPosition.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, middle);

  cross.setOrientation(LayoutPosition_cross::or_270_deg);
  delay(5000);
  Serial.println("done");
    cross.printAllPosition();

}

void loop() {
  //layoutPosition.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, LayoutPosition::abs_centerADC_point);

  joystickStatus_t* status = joystick.readStatus();

  //Position* pos = layoutPosition.getPosition(status->x, status->y, status->button_pressed);
  //layoutPosition.printPosition(pos);
  
  Position* pos = cross.getPosition(status->x, status->y, status->button_pressed);
  cross.printPosition(pos);
  
  joystick.printStatus();
  Serial.println("...........................\n\n\n");
  delay(1000);
}
