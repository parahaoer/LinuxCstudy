#include <stdio.h>
#include <time.h>
#include <unistd.h>

int getLineNum(FILE *file);

int main(int argc, char const *argv[])
{
    time_t t;
    struct tm *tv;
    char line[30];
    int lineNum;

    FILE *file = fopen("test.txt", "a+");
    // 将读写位置移动到倒数第二行中，因为一行不会超过30个字节
    if (fseek(file, -30, SEEK_END) == 0) {
        // 读取倒数第二行（包括倒数第二行包含的换行符'\n'）
        if (fgets(line, 30, file) != NULL) {
            // 获取倒数第一行的行号并加1，得到lineNum
            lineNum = getLineNum(file) + 1;
        }
    // 如果文件没有倒数第二行，只有倒数第一行
    } else if (fgets(line, 30, file) != NULL){
        lineNum = 2;
    // 文件一行都没有
    } else {
        lineNum = 1;
    }

    while (1) {
        t = time(&t);
        tv = localtime(&t);
        sprintf(line, "%d %d-%d-%d %d:%d:%d\n", lineNum++, 1900 + tv->tm_year, 1 + tv->tm_mon, tv->tm_mday, tv->tm_hour, tv->tm_min, tv->tm_sec);
        fputs(line, file);
        // 立刻将line中的内容写入文件中，否则Ctrl C后文件内容为空
        fflush(file);
        sleep(1);
    }
    fclose(file);
    return 0;
}

int getLineNum(FILE *file) {
    int lineNum = 0;
    char ch;
    while ((ch = fgetc(file)) != ' ') {
        lineNum = lineNum * 10 + ch - '0';
    }
    return lineNum;
}