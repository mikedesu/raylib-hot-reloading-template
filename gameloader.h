#pragma once

#include "gamestate.h"

#include <stdbool.h>

void myinitwindow();
void myinitwindowwithgamestate(gamestate* state);
void drawframe();
bool mywindowshouldclose();
bool myiskeypressed(int key);
void updateframecountbuffer();
unsigned int getframecount();
void gameloop();
void gamerun();
//void handleinput();
//void updategamestate();
void updateframecount();
