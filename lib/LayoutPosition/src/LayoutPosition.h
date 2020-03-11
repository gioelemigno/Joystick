#pragma once 

#include <stdint.h>
#include <stdbool.h>

#include "Arduino.h"
typedef struct point{
  uint16_t x;
  uint16_t y;
}point_t;


/******************************************************************************
                          X <-----------------------(min.x, min.y)
                                                    |
                                                    |
                                                    |
                           center     *             |
                                                    |
                                                    |
                                                    |
                          * (max.x, max.y)          V Y


  min.x = center.x - OFFSET
  min.y= center.y - OFFSET

  max.x=center.x+OFFSET
  max.y=center.y+OFFSET
*******************************************************************************/
/*
typedef struct position{
  point_t center;
  point_t min;
  point_t max;
  uint16_t ID;
  bool button_pressed;
  const char* name;
}position_t;
*/
class Position{
  public:
    //point_t center;
    point_t min;
    point_t max;
    uint16_t ID;
    bool button_pressed;
    const char* name;

    //each type of position has own calibration method
    //position depends on center(rest position of joystick) and limit of adc (min and max)
    virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
    while(1){
      Serial.println("ERRORE \n");
      delay(1000);
      }
      return;
      
    }
    
    void init(const char* _name, bool _button_pressed, uint16_t _ID){
      this->name=_name;
      this->button_pressed=_button_pressed;
      this->ID=_ID;
    }

};
/*********************************************************************************/


/**********************************************************************************
 *                         X <-----------------------min_coordinate
                                                    |
                                                    |
                                                    |
                     rest_coordinate    *           |
                                                    |
                                                    |
                                                    |
          max_coordinate   *                        V Y
 *********************************************************************************/
typedef struct _position_array{
    Position** position;
    uint16_t size;
}position_array_t;

class LayoutPosition{
   // private:
    public:
        static point_t abs_minADC_point;
        static point_t abs_maxADC_point;
        static point_t abs_centerADC_point;

        static point_t abs_unknown_point;
        
        position_array_t position;

    //public:
        LayoutPosition();

        enum id_pos_default {id_pos_rest=0, id_pos_rest_buttonPressed, id_pos_unknown};

        //add enum in inherited class

        void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point);
        
        Position* getPosition(uint16_t x, uint16_t y, bool button_pressed);

        void printPosition(Position* pos);
    void printAllPosition();

};

