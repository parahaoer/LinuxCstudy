#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0x01020304;
    char *p = (char *) &a;
    if (p[0] == 0x04) {
        printf("little byte order");
    } else if (p[0] == 0x01) {
        printf("big byte order");
    }
    return 0;
}
