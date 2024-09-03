all: game 

game: main.c libgame.so Gamestate.o
	gcc -o game main.c -l:libraylib.a -lm

Test.o: Test.c
	gcc -c -fPIC Test.c -o Test.o

Game.o: Game.c
	touch libgame.so.lockfile
	gcc -c -fPIC Game.c -o Game.o

Gamestate.o: Gamestate.c
	gcc -c -fPIC Gamestate.c -o Gamestate.o

libgame.so: Game.o Test.o Gamestate.o
	gcc -shared -o libgame.so Game.o Test.o Gamestate.o -l:libraylib.a
	rm -rfv libgame.so.lockfile

clean:
	rm -rfv game *.o *.so *.lockfile
