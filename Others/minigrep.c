/* A simple grep program that only works with:
 *
 *      minigrep [pattern] [filename]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *query;
    char *filename;
} Search;

Search parse_argments(int argc, char *argv[]);
void search_in_file(char *query, char *filename);

int main(int argc, char *argv[]) {
    Search search = parse_argments(argc, argv);
    search_in_file(search.query, search.filename);

    return EXIT_SUCCESS;
}

Search parse_argments(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Error: Insufficient argments.\n");
        fprintf(stderr, "Usage:\n\n\t%s [pattern] [filename]\n\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Search search = {.query = argv[1], .filename = argv[2]};
    return search;
}

void search_in_file(char *query, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: file not found.");
        exit(EXIT_FAILURE);
    }

    char *line;
    size_t line_size = 0;
    int line_number = 1;
    while (getline(&line, &line_size, file) != -1) {
        if (strstr(line, query) != NULL) {
            printf("%d: %s", line_number, line);
        }
        line_number++;
    }
}
