all: game 

game: main.c libgame.so
	gcc -o game main.c 

Test.o: Test.c
	gcc -c -fPIC Test.c -o Test.o

Game.o: Game.c
	touch libgame.so.lockfile
	gcc -c -fPIC Game.c -o Game.o

libgame.so: Game.o Test.o
	gcc -shared -o libgame.so Game.o Test.o -l:libraylib.a
	rm -f libgame.so.lockfile

clean:
	rm -rf game *.o *.so *.lockfile
