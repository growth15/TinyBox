#include "utility.h"

#include <errno.h>
#include <stdio.h>

void name_and_error(const char *name) {
    fprintf(stderr, "%s: %s\n", name, strerror(errno));
}

void usage(const char* msg) {
    printf("%s\n", msg);
}
