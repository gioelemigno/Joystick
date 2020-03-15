#include "CustomMapping.h"
#include "Handler.h"
#include "LayoutPosition.h"
#include <stdlib.h>
#include "Action.h"

char j = 'j';
char k = 'k';
char l = 'l';
char s = 's';
char z = 'z';

args_action_mouseRelativeMove_t args_action_mouseRelativeMove_UP;
args_action_mouseRelativeMove_t args_action_mouseRelativeMove_DOWN;
args_action_mouseRelativeMove_t args_action_mouseRelativeMove_LEFT;
args_action_mouseRelativeMove_t args_action_mouseRelativeMove_RIGHT;

//LayoutPosition_cross layoutPosition_cross;
//LayoutPosition_star layoutPosition_cross;

#define MOUSE_STEP 10
#define MOUSE_PERIOD 50
//RGB color:
#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255

#define YELLOW 255,255,0
#define VIOLET 127,0,255
#define WHITE 255,255,255
#define ORANGE 255,128,0
#define PINK 255,0,255
#define MAGENTA 255,0,127
#define BLUE_LIGHT 0,255,255

uint16_t id_position_up = LayoutPosition_cross::id_pos_up;
uint16_t id_position_left = LayoutPosition_cross::id_pos_left;
uint16_t id_position_down = LayoutPosition_cross::id_pos_down;
uint16_t id_position_right = LayoutPosition_cross::id_pos_right;
uint16_t id_position_rest_press_button = LayoutPosition_cross::id_pos_rest_buttonPressed;


CustomMapping::CustomMapping(){
  this->Mapping_F1F2F3F4->layoutPosition= &layoutPosition_cross;
  this->Mapping_F1F2F3F4 = new Handler_position();
  Mapping_F1F2F3F4->setAction(id_position_up, GlobalActionArray[id_action_pressCtrlF1], NULL, true, 0);
  Mapping_F1F2F3F4->setAction(id_position_left, GlobalActionArray[id_action_pressCtrlF2], NULL, true, 0);
  Mapping_F1F2F3F4->setAction(id_position_down, GlobalActionArray[id_action_pressCtrlF3], NULL, true, 0);
  Mapping_F1F2F3F4->setAction(id_position_right, GlobalActionArray[id_action_pressCtrlF4], NULL, true, 0);
  Mapping_F1F2F3F4->setAction(id_position_rest_press_button, GlobalActionArray[id_action_CTRL_Letter], &s, true, 0);

  Mapping_F1F2F3F4->setLedColor(GREEN, 100);
  Mapping_F1F2F3F4->setOrientation(LayoutPosition_star::or_90_deg);
/*
  this->Mapping_youtube->layoutPosition= &layoutPosition_cross;
  this->Mapping_youtube = new Handler_position();
  Mapping_youtube->setAction(id_position_rest_press_button, GlobalActionArray[id_action_typeLetter], &k, true, 0);
  Mapping_youtube->setAction(id_position_left, GlobalActionArray[id_action_typeLetter], &j, true, 0);
  Mapping_youtube->setAction(id_position_right, GlobalActionArray[id_action_typeLetter], &l, true, 0);
  Mapping_youtube->setAction(id_position_down, GlobalActionArray[id_action_volumeDown], NULL, false, 100);
  Mapping_youtube->setAction(id_position_up, GlobalActionArray[id_action_volumeUp], NULL, false, 100);
  Mapping_youtube->setLedColor(RED, 100);
  Mapping_youtube->setOrientation(LayoutPosition_star::or_90_deg);


this->Mapping_browserF1F2F3F4->layoutPosition= &layoutPosition_cross;
  this->Mapping_browserF1F2F3F4 = new Handler_position();
  Mapping_browserF1F2F3F4->setAction(id_position_rest_press_button, GlobalActionArray[id_action_typeLetter], &s, true, 0);
  Mapping_browserF1F2F3F4->setAction(id_position_up, GlobalActionArray[id_action_CTRL_Letter], &s, true, 0);
  Mapping_browserF1F2F3F4->setAction(id_position_down, GlobalActionArray[id_action_CTRL_Letter], &z, true, 0);
  Mapping_browserF1F2F3F4->setAction(id_position_left, GlobalActionArray[id_action_goBackFn], NULL, true, 0);
  Mapping_browserF1F2F3F4->setAction(id_position_right, GlobalActionArray[id_action_moveOnFn], NULL, true, 0);
  Mapping_browserF1F2F3F4->setLedColor(ORANGE, 100);
  Mapping_browserF1F2F3F4->setOrientation(LayoutPosition_star::or_90_deg);

this->Mapping_audio->layoutPosition= &layoutPosition_cross;
  this->Mapping_audio = new Handler_position();
  Mapping_audio->setAction(id_position_down, GlobalActionArray[id_action_volumeDown], NULL, false, 100);
  Mapping_audio->setAction(id_position_up, GlobalActionArray[id_action_volumeUp], NULL, false, 100);
  Mapping_audio->setAction(id_position_rest_press_button, GlobalActionArray[id_action_volumeUp], NULL, true, 0);
  Mapping_audio->setLedColor(BLUE, 100);
  Mapping_audio->setOrientation(LayoutPosition_star::or_90_deg);

this->Mapping_muose->layoutPosition= &layoutPosition_cross;
  this->Mapping_muose = new Handler_position();

  Mapping_muose->setAction(id_position_rest_press_button, GlobalActionArray[id_action_mouseClickLeft], NULL, true, 0);

  args_action_mouseRelativeMove_UP.x_relative=0;
  args_action_mouseRelativeMove_UP.y_relative=-MOUSE_STEP;
  Mapping_muose->setAction(id_position_up, GlobalActionArray[id_action_mouseRelativeMove], &args_action_mouseRelativeMove_UP, false, MOUSE_PERIOD);

  args_action_mouseRelativeMove_DOWN.x_relative=0;
  args_action_mouseRelativeMove_DOWN.y_relative=MOUSE_STEP;
  Mapping_muose->setAction(id_position_down, GlobalActionArray[id_action_mouseRelativeMove], &args_action_mouseRelativeMove_DOWN, false, MOUSE_PERIOD);

  args_action_mouseRelativeMove_LEFT.x_relative=-MOUSE_STEP;
  args_action_mouseRelativeMove_LEFT.y_relative=0;
  Mapping_muose->setAction(id_position_left, GlobalActionArray[id_action_mouseRelativeMove], &args_action_mouseRelativeMove_LEFT, false, MOUSE_PERIOD);

  args_action_mouseRelativeMove_RIGHT.x_relative=MOUSE_STEP;
  args_action_mouseRelativeMove_RIGHT.y_relative=0;
  Mapping_muose->setAction(id_position_right, GlobalActionArray[id_action_mouseRelativeMove], &args_action_mouseRelativeMove_RIGHT, false, MOUSE_PERIOD);

  Mapping_muose->setLedColor(BLUE_LIGHT, 100);
  Mapping_muose->setOrientation(LayoutPosition_star::or_90_deg);
*/
}


CustomMapping GlobalCustomMapping=CustomMapping();
