#pragma once

#include <stdint.h>
#include "Arduino.h"
#include <stdbool.h>

typedef struct _joystickStatus_t{
    uint16_t x;
    uint16_t y;
    bool button_pressed;    
}joystickStatus_t;

class Joystick{
  private:
    uint8_t pin_button;
    uint8_t pin_vrx;
    uint8_t pin_vry;

    joystickStatus_t status;

  public:
    //Joystick(){ pin_button=2; pin_vrx=A0; pin_vry=A1;}
    void begin(uint8_t _pin_button, uint8_t _pin_vrx, uint8_t _pin_vry);
    joystickStatus_t* readStatus();
    void printStatus();

    joystickStatus_t* getStatus(){return &this->status;}
    uint8_t getPin_button(){return this->pin_button;}
    uint8_t getPin_vrx(){return this->pin_vrx;}
    uint8_t getPin_vry(){return this->pin_vry;}
};