#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define REPLACE_CHAR '*'

void clean(char* buffer, const char* bad_word);

int main(int argc, char** argv) {
    FILE *fp;
    char line_buffer[BUFFER_SIZE];
    char word_buffer[BUFFER_SIZE];

    fp = fopen(argv[1], "r");

    while (fgets(line_buffer, BUFFER_SIZE, stdin) != NULL) {
        while (fgets(word_buffer, BUFFER_SIZE, fp) != NULL) {
            word_buffer[strlen(word_buffer) - 1] = '\0';
            clean(line_buffer, word_buffer);
        }
        printf("%s", line_buffer);
        fseek(fp, 0, SEEK_SET);
    }
    return 0;
}

void clean(char* buffer, const char* bad_word) {
    /* Read buffer and clean away every instance of bad_word
     */
    char* match_start;
    int i;

    while ((match_start = strstr(buffer, bad_word)) != NULL) {
        match_start++;
        for (i = strlen(bad_word) - 2; i-- >= 0;) {
            *(match_start++) = REPLACE_CHAR;
        }
    }
}
