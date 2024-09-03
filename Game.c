#include "raylib.h"
#include <stdio.h>

void MyInitWindow() {
  InitWindow(800, 450, "Game");
  SetTargetFPS(60);
}

void DrawFrame() {
  BeginDrawing();
  ClearBackground(WHITE);
  // ClearBackground(BLACK);
  DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);
  EndDrawing();
}

void MyCloseWindow() { CloseWindow(); }

bool MyWindowShouldClose() { return WindowShouldClose(); }

bool MyIsKeyPressed(int key) { return IsKeyPressed(key); }

void GameRun() {
  // while (!WindowShouldClose()) {
  //  BeginDrawing();
  //  ClearBackground(RAYWHITE);
  //  DrawText("Congrats! You created your first window!", 190, 200, 20,
  //           LIGHTGRAY);
  //  EndDrawing();
  //}
  // CloseWindow();
}
