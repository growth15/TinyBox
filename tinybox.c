#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "internal.h"

static int been_there_done_that = 0;

static const struct Applet applets[] = {
#ifdef TB_TINYBOX // bin
    {"tinybox", tinybox_main},
#endif
#ifdef TB_CAT // bin
    {"cat", cat_main},
#endif
    {0},
};

int main(int argc, char **argv) {
    char *s = argv[0];
    char *name = argv[0];
    const struct Applet *a = applets;

    while (*s != '\0') {
        if (*s++ == '/') {
            name = s;
        }
    }

    while (a->name != 0) {
        if (strcmp(name, a->name) == 0) {
            int status;

            status = ((*(a->main))(argc, argv));
            if (status < 0) {
                fprintf(stderr, "%s: %s\n", a->name, strerror(errno));
            }
            fprintf(stderr, "\n");
            exit(status);
        }
        a++;
    }
    return (tinybox_main(argc, argv));
}

int tinybox_main(int argc, char **argv) {
    argc--;
    argv++;

    /* If we've already been here once, exit now */
    if (been_there_done_that == 1) {
        return -1;
    }
    been_there_done_that = 1;

    if (argc < 1) {
        const struct Applet *a = applets;
        fprintf(stderr, "tinybox v%s (%s) multi-call binary\n", TB_VER, TB_BT);
        fprintf(stderr, "Usage: tinybox [function] [arguments]...\n");
        fprintf(stderr,
                "\n\tMost people will create a symlink to tinybox for each\n"
                "\tfunction name, and tinybox will act like whatever you "
                "invoke it as.\n");
        fprintf(stderr, "\nCurrently defined functions:\n");

        if (a->name != 0) {
            fprintf(stderr, "%s", a->name);
            a++;
        }
        while (a->name != 0) {
            fprintf(stderr, ", %s", a->name);
            a++;
        }
        fprintf(stderr, "\n\n");
        exit(-1);
    } else {
        return (main(argc, argv));
    }
}
