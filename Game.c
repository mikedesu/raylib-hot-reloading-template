#include "Test.h"
#include "raylib.h"
#include <stdio.h>

int frame_count = 0;
char frame_count_buffer[30] = {0};

void MyInitWindow();
void DrawFrame();
void MyCloseWindow();
bool MyWindowShouldClose();
bool MyIsKeyPressed(int key);

void MyInitWindow() {
  InitWindow(800, 450, "Game");
  SetTargetFPS(60);
  MyTest();
}

void UpdateFrameCountBuffer() {
  sprintf(frame_count_buffer, "evildojo666: %d", frame_count);
}

void DrawFrame() {
  BeginDrawing();
  ClearBackground(BLACK);
  DrawText(frame_count_buffer, 0, 0, 20, WHITE);
  EndDrawing();
  frame_count++;
  UpdateFrameCountBuffer();
}

void MyCloseWindow() { CloseWindow(); }
bool MyWindowShouldClose() { return WindowShouldClose(); }
bool MyIsKeyPressed(int key) { return IsKeyPressed(key); }
