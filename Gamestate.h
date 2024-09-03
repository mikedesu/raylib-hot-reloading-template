#pragma once

typedef struct Gamestate {
  unsigned int framecount;
  // const char *s = "evildojo";
} Gamestate;

Gamestate *Gamestate_init();
// void Gamestate_update(Gamestate *gamestate);
void Gamestate_destroy(Gamestate *gamestate);
