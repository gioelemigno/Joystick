#include "Controller.h"
#include "Handler.h"
#include "Joystick.h"
#include <stdint.h>
#include <stdlib.h>
#include "Keyboard.h"
#include "Mouse.h"

void Controller::setHandler(uint16_t index, Handler* handler){
    handler->setJoystck(&this->joystick);
    this->handler[index] = handler;
}

void Controller::begin(uint8_t pin_button, uint8_t pin_x, uint8_t pin_y){   
    Keyboard.begin();
    Mouse.begin();
    this->joystick.begin(pin_button, pin_x, pin_y);
    joystickStatus_t* status = joystick.readStatus();
    point_t middle = {.x=status->x, .y=status->y};
    
    for(uint16_t i = 0; i<N_HANDLER; i++){
        if(this->handler[i]==NULL) continue;
        this->handler[i]->calibration(LayoutPosition::abs_minADC_point, LayoutPosition::abs_maxADC_point, middle);
    }
}
void Controller::run(){
    //joystickStatus_t* status =  this->joystick.readStatus();
    this->handler[current_index]->runAction();
}

void Controller::setOrientation(LayoutPosition::orientation_t orientation){
    for(uint16_t i=0; i<N_HANDLER; i++){
        if(this->handler[i]==NULL) continue;
        this->handler[i]->setOrientation(orientation);
    }
}
Controller::Controller(){
    current_index=0;
}
