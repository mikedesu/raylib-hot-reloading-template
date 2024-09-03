

#include <dlfcn.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

const char *libname = "./libgame.so";
const char *lockfile = "./libgame.so.lock";
const char *templib = "./templibgame.so";

void *handle = NULL;
void (*MyInitWindow)(void) = NULL;
void (*MyDrawFrame)(void) = NULL;
void (*MyCloseWindow)(void) = NULL;
bool (*MyWindowShouldClose)(void) = NULL;
bool (*MyIsKeyPressed)(int) = NULL;

time_t last_write_time = 0;

bool FileExists(const char *filename) {
  struct stat file_stat;
  return stat(filename, &file_stat) == 0;
}

// get the last write time of a file
time_t GetLastWriteTime(const char *filename) {
  struct stat file_stat;
  time_t retval = 0;
  if (stat(filename, &file_stat) == 0) {
    retval = file_stat.st_mtime;
  }
  return retval;
}

void LoadSymbols() {
  MyInitWindow = dlsym(handle, "MyInitWindow");
  MyDrawFrame = dlsym(handle, "DrawFrame");
  MyCloseWindow = dlsym(handle, "MyCloseWindow");
  MyWindowShouldClose = dlsym(handle, "MyWindowShouldClose");
  MyIsKeyPressed = dlsym(handle, "MyIsKeyPressed");
  if (MyInitWindow == NULL || MyDrawFrame == NULL || MyCloseWindow == NULL ||
      MyWindowShouldClose == NULL || MyIsKeyPressed == NULL) {
    fprintf(stderr, "dlsym failed: %s\n", dlerror());
    exit(1);
  }
}

void OpenHandle() {
  handle = dlopen(libname, RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "dlopen failed: %s\n", dlerror());
    exit(1);
  }
}

void AutoReload() {
  if (GetLastWriteTime(libname) > last_write_time) {
    last_write_time = GetLastWriteTime(libname);
    while (FileExists(lockfile)) {
      printf("Library is locked\n");
      sleep(1);
    }
    MyCloseWindow();
    dlclose(handle);
    OpenHandle();
    LoadSymbols();
    MyInitWindow();
  }
}

int main() {
  OpenHandle();
  last_write_time = GetLastWriteTime(libname);
  LoadSymbols();
  MyInitWindow();
  while (!MyWindowShouldClose()) {
    MyDrawFrame();
    AutoReload();
  }
  MyCloseWindow();
  dlclose(handle);
  return 0;
}
