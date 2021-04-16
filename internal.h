#ifndef _INTERNAL_H_
#define _INTERNAL_H_

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "tinybox.h"

struct Applet {
    const char *name;
    int (*main)(int argc, char **argv);
};

extern int tinybox_main(int argc, char **argv);
extern void name_and_error(const char *name);
extern int cat_main(int argc, char **argv);

#endif
