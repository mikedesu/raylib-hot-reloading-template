#pragma once

#include "Gamestate.h"

#include <stdbool.h>

void MyInitWindow();
void MyInitWindowWithGamestate(Gamestate* state);
void DrawFrame();
bool MyWindowShouldClose();
bool MyIsKeyPressed(int key);
void UpdateFrameCountBuffer();
unsigned int GetFrameCount();
void GameLoop();
void GameRun();
//void HandleInput();
//void UpdateGamestate();
void UpdateFrameCount();
