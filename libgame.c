#include "libgame.h"

//#include <stdlib.h>

void updategamestate(gamestate* state) {
    // for right now, we will just update the frame count
    if(state) {
        state->framecount++;
    }
}
