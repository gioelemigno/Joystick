#pragma once 

#include <stdint.h>
#include <stdbool.h>

/*
typedef enum id_position{
    id_position_up=1,
    id_position_down,
    id_position_right,
    id_position_left,
    id_position_rest,
    id_position_unkonwn,
    id_position_rest_press_button
}id_position_t;
*/

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
typedef struct position{
  point_t center;
  point_t min;
  point_t max;
  uint16_t ID;
  bool button_pressed;
  const char* name;
}position_t;
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
    position_t* position;
    uint16_t size;
}position_array_t;

class LayoutPosition{
   // private:
    public:
        static point_t rest_coordinate;
        static point_t max_coordinate;
        static point_t min_coordinate;

        position_array_t custom_position;

    //public:
        LayoutPosition();

        uint16_t offset;

        enum id_pos_default {id_pos_rest=0, id_pos_rest_buttonPressed, id_pos_unknown};

        //add enum in inherited class
        //position_array_t pos_custom;
        void calibration(uint16_t rest_coordinate_x, uint16_t rest_coordinate_y,
                            uint16_t max_coordinate_x, uint16_t max_coordinate_y, 
                            uint16_t min_coordinate_x, uint16_t min_coordinate_y, 
                            uint16_t offset);
        
        position_t* getPosition(uint16_t x, uint16_t y, bool button_pressed);
        void setupDefaultPosition();

};

