#include "Test.h"
#include "raylib.h"
#include <stdio.h>

unsigned int frame_count = 0;

char frame_count_buffer[30] = {0};

const int default_window_width = 1280;
const int default_window_height = 720;

void MyInitWindow();
void MyInitWindowWithFrameCount(unsigned int count);
void DrawFrame();
void MyCloseWindow();
bool MyWindowShouldClose();
bool MyIsKeyPressed(int key);
void UpdateFrameCountBuffer();
unsigned int GetFrameCount();

void MyInitWindow() {
  InitWindow(default_window_width, default_window_height, "Game");
  SetTargetFPS(60);
  UpdateFrameCountBuffer();
}

void MyInitWindowWithFrameCount(unsigned int count) {
  InitWindow(default_window_width, default_window_height, "Game");
  SetTargetFPS(60);
  frame_count = count;
  UpdateFrameCountBuffer();
}

void UpdateFrameCountBuffer() {
  sprintf(frame_count_buffer, "evildojo666: %d", frame_count);
}

void DrawFrame() {
  BeginDrawing();
  Color bgc = BLACK;
  Color fgc = WHITE;
  ClearBackground(bgc);
  DrawText(frame_count_buffer, 0, 0, 40, fgc);
  DrawFPS(GetScreenWidth() - 100, 10);
  EndDrawing();
  frame_count++;
  UpdateFrameCountBuffer();
}

void MyCloseWindow() { CloseWindow(); }
bool MyWindowShouldClose() { return WindowShouldClose(); }
bool MyIsKeyPressed(int key) { return IsKeyPressed(key); }

unsigned int GetFrameCount() { return frame_count; }
