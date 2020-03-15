#pragma once
#include "Joystick.h"
#include "Handler.h"
#include "CustomLayoutPosition.h"
#define N_HANDLER 5
class Controller{
    public:
        Joystick joystick;
        Handler* handler[N_HANDLER];
        uint16_t current_index;
    public:
        Controller();
        void setHandler(uint16_t index, Handler* handler);
        void begin(uint8_t pin_button, uint8_t pin_x, uint8_t pin_y);
        void run();
        void setOrientation(LayoutPosition::orientation_t orientation);
};