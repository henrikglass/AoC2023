#ifndef AOC_UTIL_H
#define AOC_UTIL_H

#include <stdio.h>
#include <stdlib.h>

static inline char *read_input(const char *path)
{
    FILE *f = fopen(path, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;

    return string;
}

#endif /* AOC_UTIL_H */

