#include "Joystick.h"
#include "Arduino.h"

void Joystick::begin(uint8_t _pin_button, uint8_t _pin_vrx, uint8_t _pin_vry){
    this->pin_button=_pin_button;
    this->pin_vrx=_pin_vrx;
    this->pin_vry=_pin_vry;

    pinMode(this->pin_button, INPUT);
    digitalWrite(this->pin_button, HIGH); //enable pull-up resistor
}

joystickStatus_t* Joystick::readStatus(){
    this->status.x=analogRead(this->pin_vrx);
    this->status.y=analogRead(this->pin_vry);
    this->status.button_pressed= ! digitalRead(this->pin_button);

    return &this->status;
}

void Joystick::printStatus(){
    Serial.print("Status: (x,y,button_pressed) (");
    Serial.print(this->status.x);
    Serial.print(", ");
    Serial.print(this->status.y);
    Serial.print(", ");
    Serial.print(this->status.button_pressed);
    Serial.print(")\n");
}