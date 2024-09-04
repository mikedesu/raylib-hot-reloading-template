#include "Game.h"
#include "gamestate.h"
#include "mPrint.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

char frame_count_buffer[30] = {0};

const int default_window_width = 1280;
const int default_window_height = 720;

gamestate* g = NULL;

void MyInitWindow() {
    InitWindow(default_window_width, default_window_height, "Game");
    SetTargetFPS(60);
    g = gamestate_init();
    UpdateFrameCountBuffer();
}

void MyInitWindowWithGamestate(gamestate* state) {
    mPrint("MyInitWindowWithGamestate");
    InitWindow(default_window_width, default_window_height, "Game");
    SetTargetFPS(60);
    mPrint("Freeing old gamestate");
    if(g != NULL) {
        gamestate_destroy(g);
    }
    mPrint("Setting new gamestate");
    g = state;
    mPrint("Updating frame count buffer");
    UpdateFrameCountBuffer();
    mPrint("Done with MyInitWindowWithGamestatex");
}

void UpdateFrameCountBuffer() {
    sprintf(frame_count_buffer, "666: %d", g->framecount);
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
    g->framecount++;
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
    return g->framecount;
}

gamestate* Game_get_gamestate() {
    return g;
}

void Game_gamestate_destroy(gamestate* gamestate) {
    if(gamestate != NULL)
        free(gamestate);
}
