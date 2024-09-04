#include "Game.h"
#include "Gamestate.h"
#include "mPrint.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

char frame_count_buffer[30] = {0};

const int default_window_width = 1280;
const int default_window_height = 720;

Gamestate* gamestate = NULL;

void MyInitWindow() {
    InitWindow(default_window_width, default_window_height, "Game");
    SetTargetFPS(60);
    gamestate = Gamestate_init();
    UpdateFrameCountBuffer();
}

void MyInitWindowWithGamestate(Gamestate* state) {
    mPrint("MyInitWindowWithGamestate");
    InitWindow(default_window_width, default_window_height, "Game");
    SetTargetFPS(60);
    mPrint("Freeing old gamestate");
    if(gamestate != NULL) {
        Gamestate_destroy(gamestate);
    }
    mPrint("Setting new gamestate");
    gamestate = state;
    mPrint("Updating frame count buffer");
    UpdateFrameCountBuffer();
    mPrint("Done with MyInitWindowWithGamestatex");
}

void UpdateFrameCountBuffer() {
    sprintf(frame_count_buffer, "666: %d", gamestate->framecount);
}

void DrawFrame() {
    BeginDrawing();
    Color bgc = BLACK;
    Color fgc = WHITE;
    ClearBackground(bgc);
    const int fontsize = 60;
    DrawText(frame_count_buffer, GetScreenWidth() / 4, GetScreenHeight() / 4, fontsize, fgc);
    DrawFPS(GetScreenWidth() - 100, 10);
    EndDrawing();
    UpdateFrameCount();
}

void UpdateFrameCount() {
    gamestate->framecount++;
}

void GameLoop() {
    while(!WindowShouldClose()) {
        DrawFrame();
        UpdateFrameCountBuffer();
    }
}

void GameRun() {
    mPrint("GameRun");
    mPrint("initing window");
    MyInitWindow();
    mPrint("entering gameloop");
    GameLoop();
    mPrint("closing window");
    CloseWindow();
}

bool MyWindowShouldClose() {
    return WindowShouldClose();
}

bool MyIsKeyPressed(int key) {
    return IsKeyPressed(key);
}

unsigned int GetFrameCount() {
    return gamestate->framecount;
}

Gamestate* Game_get_gamestate() {
    return gamestate;
}

void Game_gamestate_destroy(Gamestate* gamestate) {
    if(gamestate != NULL)
        free(gamestate);
}
