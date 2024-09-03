# Raylib Hot Reloading in C

This project is an example of how one might go about implementing a "hot-reloading" system in C using the Raylib game development library. The idea is to allow the user to modify the game code while the game is running, and have the changes take effect immediately without having to restart the game.


# Building

This assumes you have built and installed raylib with static linking.

```
make
```

# Build Loop and Running

In one terminal, do the following:

```
unalias ls;
ls *.c Makefile | entr -s 'make'
```

In another terminal, do the following:

```
./game
```

Now, whenever you save a .c file, the game will automatically rebuild and reload the new code.

Of course, if you introduce NEW files, be sure to update the Makefile.

# Ideas For Improvement

- Instead of having to close and re-open the window, we might find a way to manage the window and drawing and have the gamestate code reload if changed, but not touch the window.

