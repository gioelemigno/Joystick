#include "Handler.h"
#include <stdlib.h>
#include "LayoutPosition.h"
#include "Joystick.h"

void defaultAction(void*){}

void Handler::setLedColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness){
  this->ledColor.red=red;
  this->ledColor.blue=blue;
  this->ledColor.green=green;
  this->ledColor.brightness=brightness;

}

Handler::Handler(){
  //actionToPerformHandler = NULL;

}




void Handler_position::setAction(uint16_t id_pos, void (*func)(void*), void* args,
                                        bool one_perform, unsigned long period){
  this->actionToPerform[id_pos].function = func;
  this->actionToPerform[id_pos].onePerform=one_perform;
  this->actionToPerform[id_pos].period=period;
  this->actionToPerform[id_pos].args=args;
}


void Handler_position::runAction(){
  joystickStatus_t* status = this->joystick->readStatus();
  Position* position = this->layoutPosition->getPosition(status->x, status->y, status->button_pressed);

  uint16_t id = position->ID;
  void* args = this->actionToPerform[id].args;

  this->actionToPerform[id].function(args);
  
  status=this->joystick->readStatus();
  position= this->layoutPosition->getPosition(status->x, status->y, status->button_pressed);
  uint16_t newID = position->ID;

  if(this->actionToPerform[id].onePerform){
    while(newID==id){
      status=this->joystick->readStatus();
      position =this->layoutPosition->getPosition(status->x, status->y, status->button_pressed);
      newID = position->ID;
    }
    return;
  }
  else{
    unsigned long _time = millis();
    unsigned long time_start = _time;
    unsigned long period = this->actionToPerform[id].period;
    while(newID==id){
      _time = millis();
      if(_time - time_start >= period){
        this->actionToPerform[id].function(args);
        time_start=_time;        
      }
      status=this->joystick->readStatus();
      position =this->layoutPosition->getPosition(status->x, status->y, status->button_pressed);
      newID = position->ID;      
    }
  }
}

Handler_position::Handler_position(){
  for(int i = 0; i<N_POSITION; i++){
    this->actionToPerform[i].function = defaultAction;
    this->actionToPerform[i].args=NULL;

    this->actionToPerform[i].onePerform = true;
    this->actionToPerform[i].period=0;

    //ISO C++ forbids that
      //this->array_Action[i]=&this->defaultAction;
  }
}




