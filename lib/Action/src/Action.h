#pragma once

void action_pressCtrlF1(void* args);
void action_pressCtrlF2(void* args);
void action_pressCtrlF3(void* args);
void action_pressCtrlF4(void* args);

void action_typeLetter(void* letter);

void action_moveOnFn(void* args);
void action_goBackFn(void* args);

void action_volumeUp(void* args);
void action_volumeDown(void* args);

void action_CTRL_Letter(void* letter);

typedef struct _args_action_mouseRelativeMove{
    int x_relative;
    int y_relative;
}args_action_mouseRelativeMove_t;
void action_mouseRelativeMove(void* args);

void action_mouseClickLeft(void* args);

typedef enum _id_action{
  id_action_pressCtrlF1 = 0,
  id_action_pressCtrlF2,
  id_action_pressCtrlF3,
  id_action_pressCtrlF4,

  id_action_typeLetter,

  id_action_moveOnFn,
  id_action_goBackFn,

  id_action_volumeUp,
  id_action_volumeDown,
  id_action_CTRL_Letter,
  id_action_mouseRelativeMove,
  id_action_mouseClickLeft
}id_action_t;

extern void (*GlobalActionArray[])(void*);