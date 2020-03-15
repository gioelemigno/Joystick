
#include "Arduino.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"
#include "LayoutPosition.h"
#include "CustomLayoutPosition.h"
//#include "Controller.h"
//#include "CustomMapping.h"

Joystick joystick;
LayoutPosition layoutPosition;
LayoutPosition_cross cross;
LayoutPosition_star star;

void setup() { 
  //joystick.begin(2, A1, A0);
  Serial.begin(9600);
      delay(5000);

  Serial.println("wainting calibartion...");
    joystickStatus_t* status = joystick.readStatus();
  point_t middle = {.x=status->x, .y=status->y};
    star.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, middle);

//  cross.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, middle);

  //layoutPosition.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, middle);

  star.setOrientation(LayoutPosition_cross::or_270_deg);

  //cross.setOrientation(LayoutPosition_cross::or_0_deg);
  delay(5000);
  Serial.println("done");
//    cross.printAllPosition();
        star.printAllPosition();


}

void loop() {
  //layoutPosition.calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, LayoutPosition::abs_centerADC_point);

  joystickStatus_t* status = joystick.readStatus();

  //Position* pos = layoutPosition.getPosition(status->x, status->y, status->button_pressed);
  //layoutPosition.printPosition(pos);
  
  //Position* pos = cross.getPosition(status->x, status->y, status->button_pressed);
  //cross.printPosition(pos);
  
    Position* pos = star.getPosition(status->x, status->y, status->button_pressed);
  star.printPosition(pos);

  joystick.printStatus();
  Serial.println("...........................\n\n\n");
  delay(1000);
}
/*
//Controller controller;
void setup(){
  Serial.begin(9600);
  //controller.begin(2,A1,A0);
  //controller.setHandler(0, GlobalCustomMapping.Mapping_F1F2F3F4);

  delay(5000);
  Serial.println("end setup..");
  
}

void loop(){
  //controller.run();
}
*/