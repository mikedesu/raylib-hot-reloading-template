#pragma once

#include "gamestate.h"

#include <stdbool.h>

void MyInitWindow();
void MyInitWindowWithGamestate(gamestate* state);
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
