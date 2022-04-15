#include <unistd.h>
#include <fcntl.h>
#include <cassert>
#include <cstdio>

void redirect_cin(const char* fname) {
  if(close(STDIN_FILENO)==-1) {
    _exit(-1);
  }
  int fd = open(fname, O_RDONLY);
  assert(fd == STDIN_FILENO);
}

int main(int argc, char* argv[]) {
  redirect_cin(argv[1]);
  char s[20];
  scanf("%s", s);
  printf("%s\n", s);
  if(close(STDIN_FILENO)==-1) {
    _exit(-1);
  }
}