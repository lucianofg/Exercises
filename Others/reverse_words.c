/**
 * Reverse words in a string in place
 */
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_not_space_char(char c) { 
    return !(c == ' ' || c == '\n' || c == '\t'); 
}

void reverse_words_in_string(char **str) {
    int start = 0;
    int end = 0;
    while ((*str)[end] != '\0') {
        while (is_not_space_char((*str)[end])) {
            if ((*str)[end] == '\0') {
                break;
            }
            end++;
        }
        for (int i = start; i < (((end - start) / 2) + start); i++) {
            char tmp = (*str)[i];
            (*str)[i] = (*str)[end - i - 1 + start];
            (*str)[end - i - 1 + start] = tmp;
        }
        start = ++end;
    }
}

int main(int argc, char *argv[]) {
    /**
     * Tests:
     */

    char *test_data_01 = malloc(32);
    char *test_result_01 = malloc(32);

    strcpy(test_data_01, "Hello World");
    strcpy(test_result_01, "olleH dlroW");

    reverse_words_in_string(&test_data_01);
    assert(strcmp(test_data_01, test_result_01) == 0);


    char *test_data_02 = malloc(32);
    char *test_result_02 = malloc(32);

    strcpy(test_data_02, "uma palavra");
    strcpy(test_result_02, "amu arvalap");

    reverse_words_in_string(&test_data_02);
    assert(strcmp(test_data_02, test_result_02) == 0);


    char *test_data_03 = malloc(32);
    char *test_result_03 = malloc(32);

    strcpy(test_data_03, "OuTro");
    strcpy(test_result_03, "orTuO");

    reverse_words_in_string(&test_data_03);
    assert(strcmp(test_data_03, test_result_03) == 0);


    char *test_data_04 = malloc(32);
    char *test_result_04 = malloc(32);

    strcpy(test_data_04, "");
    strcpy(test_result_04, "");

    reverse_words_in_string(&test_data_04);
    assert(strcmp(test_data_04, test_result_04) == 0);

    /**
     * char *line;
     * size_t line_size = 0;
-    * getline(&line, &line_size, stdin);
     *
     * reverse_words_in_string(&line);
     * printf("%s\n", line);
     */

    return 0;
}
