

#include <dlfcn.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// get the last write time of a file
time_t GetLastWriteTime(const char *filename) {
  struct stat file_stat;
  if (stat(filename, &file_stat) != 0) {
    return 0;
  }
  return file_stat.st_mtime;
}

int main() {
  const char *libname = "./libgame.so";
  const char *lockfile = "./libgame.so.lock";

  void *handle = dlopen(libname, RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "dlopen failed: %s\n", dlerror());
    exit(1);
  }

  time_t last_write_time = GetLastWriteTime(libname);

  void (*MyInitWindow)(void) = dlsym(handle, "MyInitWindow");
  void (*MyDrawFrame)(void) = dlsym(handle, "DrawFrame");
  void (*MyCloseWindow)(void) = dlsym(handle, "MyCloseWindow");
  bool (*MyWindowShouldClose)(void) = dlsym(handle, "MyWindowShouldClose");
  bool (*MyIsKeyPressed)(int) = dlsym(handle, "MyIsKeyPressed");

  MyInitWindow();
  while (!MyWindowShouldClose()) {

    // if (MyIsKeyPressed(82)) {
    //   MyCloseWindow();
    //   dlclose(handle);
    //   handle = dlopen(libname, RTLD_LAZY);
    //   if (!handle) {
    //     fprintf(stderr, "dlopen failed: %s\n", dlerror());
    //     exit(1);
    //   }
    //   MyInitWindow = dlsym(handle, "MyInitWindow");
    //   MyDrawFrame = dlsym(handle, "DrawFrame");
    //   MyCloseWindow = dlsym(handle, "MyCloseWindow");
    //   MyWindowShouldClose = dlsym(handle, "MyWindowShouldClose");
    //   MyIsKeyPressed = dlsym(handle, "MyIsKeyPressed");
    //   if (MyInitWindow == NULL || MyDrawFrame == NULL ||
    //       MyCloseWindow == NULL || MyWindowShouldClose == NULL ||
    //       MyIsKeyPressed == NULL) {
    //     fprintf(stderr, "dlsym failed: %s\n", dlerror());
    //     exit(1);
    //   }
    //   printf("Reloaded library SUCCESS\n");
    // }

    MyDrawFrame();
  }
  MyCloseWindow();

  dlclose(handle);

  return 0;
}
