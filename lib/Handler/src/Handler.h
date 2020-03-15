#ifndef MAPPING_H_
#define MAPPING_H_
#include <stdbool.h>
#include "Arduino.h"
#include <stdint.h>
#include "Joystick.h"
#include "CustomLayoutPosition.h"
#define N_POSITION 10



typedef struct _actionToPerform{
  void (*function)(void*);
  void* args;
  bool onePerform; //avoid repeat action if position is not changed
  unsigned long period; // use only if onePerform is false
                        // indicates period to repeat action
}actionToPerform_t;

typedef struct _colorRGB{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t brightness;
}colorRGB_t;



class Handler{

  public:

    Handler();
    Joystick* joystick;
    colorRGB_t ledColor;
    void setLedColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness);
    void setJoystck(Joystick* _joystick){this->joystick=_joystick;}
    virtual void runAction(){return;}
    virtual void setOrientation(LayoutPosition::orientation_t orientation){return;}
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){return;}
};

class Handler_position : public Handler{
  public:
    LayoutPosition* layoutPosition;
    actionToPerform_t actionToPerform[N_POSITION];

    Handler_position();
    void setLayoutPosition(LayoutPosition* layout){this->layoutPosition=layout;}
    void setAction(uint16_t id_pos, void (*func)(void*), void* args,
                                bool one_perform, unsigned long period);
    virtual void runAction();
    virtual void setOrientation(LayoutPosition::orientation_t orientation){
      this->layoutPosition->setOrientation(orientation);
    }
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
      this->layoutPosition->calibration(abs_minADC_point, abs_maxADC_point, abs_centerADC_point);
    }

};

#endif/*MAPPING_H_*/
