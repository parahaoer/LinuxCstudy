#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    if (argc != 3) {
        printf("Using cpfile srcPath dstPath");
        exit(EXIT_FAILURE);
    }
    const char *srcPath = argv[1];
    const char *dstPath = argv[2];
    FILE *srcFile, *dstFile;
    int ch;
    if ((srcFile = fopen(srcPath, "r")) == NULL) {
        perror("open file fail");
        exit(EXIT_FAILURE);
    }
    if ((dstFile = fopen(dstPath, "w+")) == NULL) {
        perror("open file fail");
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, dstFile);
    }
    fclose(dstFile);
    fclose(srcFile);
    return 0;
}
