#include "gameloader.h"
#include "gamestate.h"
#include "mprint.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

char frame_count_buffer[30] = {0};

const int default_window_width = 1280;
const int default_window_height = 720;

gamestate* g = NULL;

void myinitwindow() {
    InitWindow(default_window_width, default_window_height, "Game");
    SetTargetFPS(60);
    g = gamestate_init();
    updateframecountbuffer();
}

void myinitwindowwithgamestate(gamestate* state) {
    mprint("myinitwindowwithgamestate");
    InitWindow(default_window_width, default_window_height, "Game");
    SetTargetFPS(60);
    mprint("freeing old gamestate");
    if(g != NULL) {
        gamestate_destroy(g);
    }
    mprint("setting new gamestate");
    g = state;
    mprint("updating frame count buffer");
    updateframecountbuffer();
    mprint("done with myinitwindowwithgamestatex");
}

void updateframecountbuffer() {
    sprintf(frame_count_buffer, "666: %d", g->framecount);
}

void drawframe() {
    BeginDrawing();
    Color bgc = BLACK;
    Color fgc = WHITE;
    ClearBackground(bgc);
    const int fontsize = 60;
    DrawText(frame_count_buffer, GetScreenWidth() / 4, GetScreenHeight() / 4, fontsize, fgc);
    DrawFPS(GetScreenWidth() - 100, 10);
    EndDrawing();
    updateframecount();
}

void updateframecount() {
    g->framecount++;
}

void gameloop() {
    while(!WindowShouldClose()) {

        //updategamestate(g);

        drawframe();
        updateframecountbuffer();
    }
}

void gamerun() {
    mprint("gamerun");
    mprint("initing window");
    myinitwindow();
    mprint("entering gameloop");
    gameloop();
    mprint("closing window");
    CloseWindow();
}

bool mywindowshouldclose() {
    return WindowShouldClose();
}

bool myiskeypressed(int key) {
    return IsKeyPressed(key);
}

unsigned int getframecount() {
    return g->framecount;
}

gamestate* game_get_gamestate() {
    return g;
}

void game_gamestate_destroy(gamestate* gamestate) {
    if(gamestate != NULL)
        free(gamestate);
}
