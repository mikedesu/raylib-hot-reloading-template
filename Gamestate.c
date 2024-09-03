#include "Gamestate.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// have to update this function when we introduce new fields to Gamestate
Gamestate *Gamestate_init() {
  Gamestate *gamestate = malloc(sizeof(Gamestate));
  if (gamestate == NULL) {
    fprintf(stderr, "Failed to allocate memory for gamestate: %s\n",
            strerror(errno));
    return NULL;
  }
  gamestate->framecount = 0;
  return gamestate;
}

// have to update this function when we introduce new fields to Gamestate
void Gamestate_destroy(Gamestate *gamestate) {
  if (gamestate == NULL) {
    fprintf(stderr, "Gamestate_destroy: gamestate is NULL\n");
    return;
  }

  free(gamestate);
}
