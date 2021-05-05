#include "usage.h"
#include "stdlib.hh"

void *xmalloc(size_t size)
{
    // stubbed: no graphics
    return NULL;
}

void wrap_modeline(char* filename, bool here) {
    char perms[] = " %%*-";
    char newfile[] = "--(New File)";
    for (int i = 0; perms[i]; i++) {
	console[(CONSOLE_ROWS - 2) * CONSOLE_COLUMNS + i] = perms[i] | 0xf000;
    }

    int i, j = 0;
    for (i = 0; filename[i]; i++) {
	console[(CONSOLE_ROWS - 2) * CONSOLE_COLUMNS + 5 + i] = filename[i] | 0xf000;
    }

    if (!here) {
	for (j = 0; newfile[j]; j++) {
	    console[(CONSOLE_ROWS - 2) * CONSOLE_COLUMNS + 5 + i + j] = newfile[j] | 0xf000;
	}
    }

    for (int k = i+j+5; k < CONSOLE_COLUMNS; k++) {
	for (j = 0; newfile[j]; j++) {
	    console[(CONSOLE_ROWS - 2) * CONSOLE_COLUMNS + k] = '-' | 0xf000;
	}
    }
}
