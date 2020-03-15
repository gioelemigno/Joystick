#include "Action.h"
#include "Arduino.h"
#include "Keyboard.h"
#include "Mouse.h"
#define N_FN 4

int Fn[N_FN] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4};
int indexFn=0;

void action_moveOnFn(void* args){
  indexFn = (indexFn+1) % N_FN;
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(Fn[indexFn]);
  delay(100);
  Keyboard.releaseAll();
}
void action_goBackFn(void* args){
  if(indexFn == 0) indexFn = N_FN-1;
  else indexFn--;
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(Fn[indexFn]);
  delay(100);
  Keyboard.releaseAll();

}

void action_pressCtrlF1(void* args){

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_F1);
  delay(100);
  Keyboard.releaseAll();

}
void action_pressCtrlF2(void* args){

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_F2);
  delay(100);
  Keyboard.releaseAll();

}
void action_pressCtrlF3(void* args){

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_F3);
  delay(100);
  Keyboard.releaseAll();

}
void action_pressCtrlF4(void* args){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_F4);
  delay(100);
  Keyboard.releaseAll();
}

void action_typeLetter(void* args){
//  unsigned char c = 'h';
  uint8_t* let_to_write = (uint8_t*)args ;
  //Serial.println(*let_to_write);
  Keyboard.write(*let_to_write);
}

void action_volumeUp(void* args){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.releaseAll();
}
void action_volumeDown(void* args){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.releaseAll();
}



void action_CTRL_Letter(void* args){
  Keyboard.press(KEY_LEFT_CTRL);
  uint8_t* let_to_write = (uint8_t*)args ;
  //Serial.println(*let_to_write);
  Keyboard.write(*let_to_write);
  delay(100);
  Keyboard.releaseAll();
}

void action_mouseRelativeMove(void* args){
  args_action_mouseRelativeMove_t* move = (args_action_mouseRelativeMove_t*) args;
  int move_x = move->x_relative;
  int move_y = move->y_relative;
/*
  Serial.print("move: ( ");
  Serial.print(move_x);
  Serial.print(", ");
  Serial.print(move_y);
  Serial.println(")");
  */
  Mouse.move(move_x, move_y);
}
 void action_mouseClickLeft(void* args){
   Mouse.click(MOUSE_LEFT);
 }

void (*GlobalActionArray[])(void*) = {
  action_pressCtrlF1,
  action_pressCtrlF2,
  action_pressCtrlF3,
  action_pressCtrlF4,

  action_typeLetter,

  action_moveOnFn,
  action_goBackFn,

  action_volumeUp,
  action_volumeDown,
  action_CTRL_Letter,
  action_mouseRelativeMove,
  action_mouseClickLeft
};