#include <unistd.h>
#include <fcntl.h>
#include <cassert>
#include <stdio.h>

void redirect_cout(const char* fname) {
  if(close(STDOUT_FILENO)==-1) _exit(-1);
  int fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  assert(fd == STDOUT_FILENO);
}

int main(int argc, char* argv[]) {
  redirect_cout(argv[1]);
  for(int i=0; i<10; ++i) {
    printf("%d", i);
  }
  // 有缓存，flush以调用系统调用
  fflush(stdout);
  if(close(STDOUT_FILENO)==-1) {
    _exit(-1);
  }
}