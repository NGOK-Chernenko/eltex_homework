#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"
#define BUF_SIZE 512

int main(void) {
  FILE *fifo;
  char *buf;

  if (mkfifo("myfifo", S_IRWXU) == -1) {
    fprintf(stderr, "Can't create fifo\n");
    return 1;
  }

  fifo = fopen(FIFO_NAME, "r");
  if (fifo == NULL) {
    fprintf(stderr, "Cannot open fifo\n");
    return 1;
  }

  buf = (char *)malloc(BUF_SIZE);
  if (buf == NULL) {
    fprintf(stderr, "malloc () error\n");
    return 1;
  }
  fscanf(fifo, "%s", buf);
  printf("%s\n", buf);
  fclose(fifo);
  free(buf);
  unlink(FIFO_NAME);
  return 0;
}