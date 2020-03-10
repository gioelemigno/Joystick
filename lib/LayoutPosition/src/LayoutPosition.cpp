#include "LayoutPosition.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//ADC
#define MAX  1023
#define MIN   0
#define MIDDLE  (uint16_t) MAX/2

#define OFFSET  20

#define SIZE_DEFAULT_POSITION   3

#define UNKONWN_COORDINATE_X    MAX+50
#define UNKONWN_COORDINATE_Y    MAX+50

static inline void setupPosition(position_array_t* position_to_set, uint16_t id, 
                            uint16_t center_x, uint16_t center_y, 
                            bool button_pressed, const char* name);

point_t LayoutPosition::rest_coordinate = {.x=MIDDLE, .y=MIDDLE};
point_t LayoutPosition::max_coordinate = {.x=MAX, .y=MAX};
point_t LayoutPosition::min_coordinate = {.x=MIN, .y=MIN};

position_t default_position_array[SIZE_DEFAULT_POSITION];

//position_array_t LayoutPosition::custom_position = {.position=default_position_array,
 //                                                           .size=SIZE_DEFAULT_POSITION};


void LayoutPosition::calibration(uint16_t rest_coordinate_x, uint16_t rest_coordinate_y,
                            uint16_t max_coordinate_x, uint16_t max_coordinate_y, 
                            uint16_t min_coordinate_x, uint16_t min_coordinate_y,
                            uint16_t offset){
    
    return;
}

LayoutPosition::LayoutPosition(){
    this->custom_position.position=default_position_array;
    this->custom_position.size=SIZE_DEFAULT_POSITION;
}

void LayoutPosition::setupDefaultPosition(){
    setupPosition(&(this->custom_position), this->id_pos_rest, rest_coordinate.x, rest_coordinate.y, false, "Rest");
    setupPosition(&(this->custom_position), this->id_pos_rest_buttonPressed, rest_coordinate.x, rest_coordinate.y, true, "Rest Button Pressed");
    setupPosition(&(this->custom_position), this->id_pos_unknown, UNKONWN_COORDINATE_X, UNKONWN_COORDINATE_Y, false, "Unknown");
}

position_t* LayoutPosition::getPosition(uint16_t x, uint16_t y, bool button_pressed){
    return NULL;
}

static inline void setupPosition(position_array_t* position_to_set, uint16_t id, 
                            uint16_t center_x, uint16_t center_y, 
                            bool button_pressed, const char* name){

    position_to_set->position[id].ID=id;

    position_to_set->position[id].center.x=center_x;
    position_to_set->position[id].center.y=center_y;

    position_to_set->position[id].button_pressed=button_pressed;

    position_to_set->position[id].name=name;
}