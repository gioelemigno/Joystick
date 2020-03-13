#include "LayoutPosition.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "Arduino.h"
//ADC
#define MAX  1023
#define MIN   0
#define MIDDLE  (uint16_t) MAX/2

#define OFFSET  20


#define UNKNOWN_OVERLOAD 2
#define UNKONWN_COORDINATE_X    MAX+UNKNOWN_OVERLOAD
#define UNKONWN_COORDINATE_Y    MAX+UNKNOWN_OVERLOAD

#define SIZE_EDGE_REST_POS 40

point_t LayoutPosition::abs_centerADC_point = {.x=MIDDLE, .y=MIDDLE};
point_t LayoutPosition::abs_maxADC_point = {.x=MAX, .y=MAX};
point_t LayoutPosition::abs_minADC_point = {.x=MIN, .y=MIN};
point_t LayoutPosition::abs_unknown_point = {.x=UNKONWN_COORDINATE_X, .y=UNKONWN_COORDINATE_Y};
//const uint16_t LayoutPosition::n_pos_default = SIZE_DEFAULT_POSITION;

static inline void printPoint(point_t p){
  Serial.print(" (");
  Serial.print(p.x);
  Serial.print(", ");
  Serial.print(p.y);
  Serial.print(") ");
}
class Position_rest: public Position{
    private:
        uint8_t sideEdge;
    public:
        void setSideEdge(uint8_t size_side_edge){this->sideEdge=size_side_edge;}
        
        Position_rest(){
            this->sideEdge=SIZE_EDGE_REST_POS;
            this->init("Rest", false, LayoutPosition::id_pos_rest);
        }
        virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point)override{
           // while(1){
             //   Serial.println("ok");
            //    delay(1000);
           // }
            uint16_t half_edge = (uint16_t) (this->sideEdge / 2);

            uint16_t x = abs_centerADC_point.x - half_edge;
            uint16_t y = abs_centerADC_point.y - half_edge;
            this->min.x= (x >= abs_minADC_point.x)? x : abs_minADC_point.x; 
            this->min.y= (y >= abs_minADC_point.y)? y : abs_minADC_point.y; 

            x=abs_centerADC_point.x + half_edge;
            y=abs_centerADC_point.y + half_edge;
            this->max.x=(x <= abs_maxADC_point.x)? x : abs_maxADC_point.x;
            this->max.y=(y <= abs_maxADC_point.y)? y : abs_maxADC_point.y;

        }

        /**********************
                     _______|||_______
                    |                 |
                    |                 |
                    |       +++       |
                    |       +++       |
                    |       +++       |
                    |                 |
                    |_________________|
             
        **********************/
};

class Position_rest_buttonPressed: public Position{
    private:
        uint8_t sideEdge;
    public:
        void setSideEdge(uint8_t size_side_edge){this->sideEdge=size_side_edge;}
        
        Position_rest_buttonPressed(){
            this->sideEdge=SIZE_EDGE_REST_POS;
            this->init("Rest Button Pressed", true, LayoutPosition::id_pos_rest_buttonPressed);
        }

        virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point)override{
            uint16_t half_edge = (uint16_t) (this->sideEdge / 2);

            uint16_t x = abs_centerADC_point.x - half_edge;
            uint16_t y = abs_centerADC_point.y - half_edge;
            this->min.x= (x >= abs_minADC_point.x)? x : abs_minADC_point.x; 
            this->min.y= (y >= abs_minADC_point.y)? y : abs_minADC_point.y; 

            x=abs_centerADC_point.x + half_edge;
            y=abs_centerADC_point.y + half_edge;
            this->max.x=(x <= abs_maxADC_point.x)? x : abs_maxADC_point.x;
            this->max.y=(y <= abs_maxADC_point.y)? y : abs_maxADC_point.y;

        }

        /**********************
                     _______|||_______
                    |                 |
                    |                 |
                    |       +++       |
                    |       +++       |
                    |       +++       |
                    |                 |
                    |_________________|
             
        **********************/
};

class Position_unknown: public Position{
    public:
        Position_unknown(){
            this->init("Unknown", false, LayoutPosition::id_pos_unknown);
        }

        virtual void calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point)override{
            //unreachable point
            this->min.x=abs_maxADC_point.x+1;
            this->min.y=abs_maxADC_point.y+1;

            this->max.x=abs_maxADC_point.x+2;
            this->max.y=abs_maxADC_point.y+2;


            /**********************
                     _______
                    |  |||  |
                    |   o   |
                    |_______|
                ++++
                +  +
                ++++                
             **********************/
        }
};

Position_rest position_rest;
Position_rest_buttonPressed position_rest_buttonPressed;
Position_unknown position_unknown;

Position* default_position_array[SIZE_DEFAULT_POSITION]{
    [LayoutPosition::id_pos_rest] = &position_rest,
    [LayoutPosition::id_pos_rest_buttonPressed] = &position_rest_buttonPressed,
    [LayoutPosition::id_pos_unknown] = &position_unknown
};




void LayoutPosition::calibration(point_t abs_minADC_point, point_t abs_maxADC_point, point_t abs_centerADC_point){
    this->abs_minADC_point=abs_minADC_point;
    this->abs_maxADC_point=abs_maxADC_point;
    this->abs_centerADC_point=abs_centerADC_point;

    this->abs_unknown_point.x=abs_maxADC_point.x +UNKNOWN_OVERLOAD;
    this->abs_unknown_point.y=abs_maxADC_point.y + UNKNOWN_OVERLOAD;
    for(uint16_t i=0; i<this->position.size; i++){
        this->position.position[i]->calibration(abs_minADC_point, abs_maxADC_point, abs_centerADC_point);
    }
    return;
}

LayoutPosition::LayoutPosition(){
    //this->n_pos_default=SIZE_DEFAULT_POSITION;
    this->position.position=default_position_array;
    this->position.size=SIZE_DEFAULT_POSITION;
    this->setOrientation(LayoutPosition::or_0_deg);
    this->calibration(this->abs_minADC_point, this->abs_maxADC_point, this->abs_centerADC_point);

}

static void static_printPosition(Position* pos){
  Serial.println("***********************************");
  Serial.print("Name:\t");
  Serial.println(pos->name);

  Serial.print("Min:\t");
  printPoint(pos->min);
  Serial.print("\n");

  Serial.print("Max:\t");
  printPoint(pos->max);
  Serial.print("\n");

  Serial.print("ID:\t");
  Serial.println(pos->ID);

}

//#define DEBUG
static bool pointInsidePosition(point_t* point, Position* position){
  #ifdef DEBUG
        Serial.println("++++++++++++++++++++++++++");

  Serial.println("********************");
  Serial.print("Coordinate:\t");
  printPoint(*point);
  Serial.print("\n");
  Serial.println("Compare with:\n");

    static_printPosition(position);
          Serial.println("++++++++++++++++++++++++++");

  Serial.println("");
  #endif /*DEBUG*/
    if(point->x >= position->min.x && point->x <= position->max.x
      && point->y >= position->min.y && point->y <= position->max.y){

      return true;
    }
    else return false;
}

Position* LayoutPosition::getPosition(uint16_t x, uint16_t y, bool button_pressed){

    point_t point = {.x=x, .y=y};
    for(uint16_t i = 0; i< this->position.size; i++){

        if(this->position.position[i]->button_pressed != button_pressed) continue;

        if(pointInsidePosition(&point, this->position.position[i])){
            return this->position.position[i];
        }
    }

    return this->position.position[LayoutPosition::id_pos_unknown];
}



void LayoutPosition::printPosition(Position* pos){
  Serial.println("***********************************");
  Serial.print("Name:\t");
  Serial.println(pos->name);

  Serial.print("Min:\t");
  printPoint(pos->min);
  Serial.print("\n");

  Serial.print("Max:\t");
  printPoint(pos->max);
  Serial.print("\n");

  Serial.print("ID:\t");
  Serial.println(pos->ID);

}

void LayoutPosition::printAllPosition(){
    for(uint16_t i=0; i< this->position.size; i++){
        printPosition(this->position.position[i]);
    }
}
