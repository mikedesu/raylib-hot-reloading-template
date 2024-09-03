


all: game 

game: main.c libgame.so
	gcc -o game main.c -l:libraylib.a -lm


Game.o: Game.c
	touch libgame.so.lockfile
	gcc -c -fPIC Game.c -o Game.o

libgame.so: Game.o
	gcc -shared -o libgame.so Game.o -l:libraylib.a
	rm -f libgame.so.lockfile




clean:
	rm -rf game *.o *.so *.lockfile
