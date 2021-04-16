#include <stdio.h>

#include "internal.h"

const char cat_usage[] = "[file ...]";

int cat_main(int argc, char **argv) {
    int c;
    FILE *file = stdin;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s %s", *argv, cat_usage);
        return 1;
    }
    argc--;
    argv++;

    while (argc-- > 0) {
        file = fopen(*argv, "r");
        if (file == NULL) {
            name_and_error(*argv);
            return 1;
        }
        while ((c = getc(file)) != EOF) {
            putc(c, stdout);
        }
        fclose(file);
        fflush(stdout);

        argc--;
        argv++;
    }
    return 0;
}
