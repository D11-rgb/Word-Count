#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 函数声明
int count_words(FILE *file);
int count_chars(FILE *file);

int main(int argc, char *argv[]) {
    if (argc < 2 || strcmp(argv[1], "-h") == 0) {
        printf("用法: wordCount.exe [-c|-w] [filename]\n");
        printf("\t-c 统计字符数\n");
        printf("\t-w 统计单词数\n");
        return 0;
    }

    const char *filename = "input.txt";
    int option = (strcmp(argv[1], "-c") == 0) ? 1 : 0; // 0 for -w, 1 for -c

    if (argc > 2) {
        filename = argv[2];
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "无法打开文件: %s\n", filename);
        return 1;
    }

    int count = (option == 0) ? count_words(file) : count_chars(file);
    printf(" %d\n", count);
    fclose(file);

    return 0;
}

// 统计单词数
int count_words(FILE *file) {
    int count = 0;
    int last_char_was_letter = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            if (!last_char_was_letter) {
                count++;
            }
            last_char_was_letter = 1;
        } else {
            last_char_was_letter = 0;
        }
    }

    return count;
}

// 统计字符数
int count_chars(FILE *file) {
    int count = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        count++;
    }

    return count;
}