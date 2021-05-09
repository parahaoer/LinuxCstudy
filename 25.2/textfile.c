#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *fp;
  int ch;
  if ((fp = fopen("text2.txt", "a+")) == NULL) {
    perror("open file fail");
    exit(1);
  }
  while ((ch == getchar()) != EOF) {
    fputc(ch, fp);
  }
  rewind(fp);
  while ((ch == fgetc((fp))) != EOF) {
    putchar(ch);
  }
}