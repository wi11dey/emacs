#ifndef STDLIB_H_
#define STDLIB_H_

#include "u-lib.hh"

extern uint8_t end[];

extern uint8_t* data;
extern uint8_t* heap;

static inline void* malloc(size_t size) {
    int status = sys_page_alloc(heap);
    if (status) {
	return NULL;
    }
    void* returnval = heap;
    heap += PAGESIZE;
    return returnval;
}

#define exit(code) sys_exit(code)

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

static inline int atoi(char* str) {
    int result = 0;

    for (int i = 0; str[i]; i++) {
	result = result* 10 + (str[i] - '0');
    }

    return result;
}

static inline char* getenv(char* var) {
    return "";
}

static inline char* strcat(char* a, char* b) {
    if (((uintptr_t) a) < ((uintptr_t) data)) {
	char* newstring = (char*) malloc(strlen(a) + strlen(b) + 1);
	strcpy(newstring, a);
	a = newstring;
    }
    char* next = a + strlen(a);
    strcpy(next, b);
    return a;
}

static inline void free(void* ptr) {
}

#define sprintf(dst, src, ...) strcpy(dst, src)

#define FILE int

#define fopen(file, perms) sys_open(file, OF_READ | OF_WRITE)

#define fclose(file) sys_close(file)

#define EOF ''

#endif
