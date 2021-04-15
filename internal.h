#ifndef _INTERNAL_H_
#define _INTERNAL_H_

#include "tinybox.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct Applet {
    const char *name;
    int (*main)(int argc, char **argv);
};

extern int tinybox_main(int argc, char **argv);

#endif
