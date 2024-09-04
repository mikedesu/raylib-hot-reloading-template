CC=gcc
OBJ=-c
SHARED=-shared
LIBGAME_OBJECTS=Game.o Gamestate.o
STATIC_LINK_RAYLIB=-l:libraylib.a
LINK_MATH=-lm
POSITION_INDEPENDENT_CODE=-fPIC
MAIN_C=main.c

all: game 

#game: main.c libgame.so Gamestate.o
game: main.c Game.o Gamestate.o
	$(CC) -o $@ $(MAIN_C) Game.o Gamestate.o $(STATIC_LINK_RAYLIB) $(LINK_MATH)

Game.o: Game.c
	#touch libgame.so.lockfile
	$(CC) $(OBJ) $(POSITION_INDEPENDENT_CODE) $^ -o $@

Gamestate.o: Gamestate.c
	$(CC) $(OBJ) $(POSITION_INDEPENDENT_CODE)  $^ -o $@
	#$(CC) $(OBJ) $(POSITION_INDEPENDENT_CODE) $(STATIC_LINK_RAYLIB) $^ -o $@

#libgame.so: $(LIBGAME_OBJECTS)
	#$(CC) $(SHARED) -o libgame.so $(LIBGAME_OBJECTS) $(STATIC_LINK_RAYLIB)
	#rm -rfv libgame.so.lockfile

clean:
	rm -rfv game *.o *.so *.lockfile
